/*
	Исходный код программки для соединения всех модулей в один файл.

	Требования для нормальной работы:
		- Все модули должны находиться в одной папке и иметь расширение *.cpp
		- В этой же папке должен лежать файл с includ'ами и тоже иметь расширение *.cpp (надо будет исправить, хотя, это не очень хуёво)
		- В папке не должно находиться других файлов с расширением *.cpp (надо будет исправить, а то это довольно хуёво) 

	Все модули собираются в файле "5306lib.cpp".

	Не работает:
		- Автоматическая сборка заголовочного файла, потому что регэкспы сложные
*/


using System;
using System.IO;
using System.Text.RegularExpressions;

class Merge{
	public struct settings{
		public string headerName;
		public string cppName;
		public string[] exceptions;
	};

	static void Main(string[] args){
		string settingsPath = "mergeSettings.txt";
		settings Settings = GetSettings (settingsPath);
		//string headerName = "5306lib.h";
		//string cppName = "5306lib.cpp";
		string[] target_h = new string[2000];
		string[] target_cpp = new string[500];
		//Getting all files in current directory
		Console.WriteLine ("Current directory is: {0}", AppDomain.CurrentDomain.BaseDirectory);
		string[] allFiles = Directory.GetFiles (AppDomain.CurrentDomain.BaseDirectory);
		for(int i = 0; i < allFiles.Length; i++) {
			Console.WriteLine (allFiles [i]);
		}

		//Divide all files into categories 
		string[] allFiles_cpp = new string[allFiles.Length];
		string[] allFiles_h = new string[allFiles.Length];
		string README;
		string[] tempString;
		int count_cpp = 0;
		int count_h = 0;
		//string[] tempFileName;
		bool GotException = false;
		for (int i = 0; i < allFiles.Length; i++) {
			tempString = GetArgs (allFiles [i], '.');
			GotException = false;
			Console.Write ("{0}: ", i);
			switch (tempString [1]) {
			case "cpp":
				if (allFiles [i].Contains (Settings.cppName)) {
					//target_cpp = File.ReadAllLines (allFiles [i]);
					Console.WriteLine ("Found target file.");

				}else{
					for (int j = 0; j < Settings.exceptions.Length; j++) {
						
						Console.WriteLine ("Comparing {0} with {1}",allFiles[i], Settings.exceptions[j]);
						if (allFiles [i] == (AppDomain.CurrentDomain.BaseDirectory + Settings.exceptions [j])) {
							Console.WriteLine ("Got exception {0}", allFiles [i]);
							GotException = true;
						}

					}
					if (!GotException) {
						allFiles_cpp [count_cpp] = allFiles [i];
					}

				}
				count_cpp++;
				break;
			case "h":
				Console.WriteLine ("Got header file");
				if (allFiles [i].Contains (Settings.headerName)) {
					
					target_h = File.ReadAllLines (allFiles [i]);
				} else {
					allFiles_h [count_h] = allFiles [i];
				}
				count_h++;
				break;
			case "md":
				Console.WriteLine ("Readme");
				README = allFiles [i];
				break;
			}
		}
		Array.Resize (ref allFiles_cpp, count_cpp);
		Array.Resize (ref allFiles_h, count_h);

		//Add files to big pile
		string[] bigCppArray = new string[2000];
		int k = 0;
		for(int i = 0; i < allFiles_cpp.Length - 1; i++){
			string[] tempArray = File.ReadAllLines (allFiles_cpp [i]);
			for (int j = 0; j < tempArray.Length; j++) {
				bigCppArray [k] = tempArray [j];
				k++;
			}
		}
		Array.Resize (ref bigCppArray, k);
		File.WriteAllLines (Settings.cppName, bigCppArray);

		Console.WriteLine ("Writing exceptions...");
		for (int i = 0; i < Settings.exceptions.Length; i++) {
			Console.WriteLine (Settings.exceptions[i]);
		}

  }

	public static string[] GetArgs(string command, char punctuation = ' ') {
		string tempCommand;
		string[] Arguments = new string[0];
		char TempChar = ' ';
		int arg = 0;
		tempCommand = command;
		for(int i = 0; i < tempCommand.Length; i++) {
			TempChar = tempCommand[i];
			if(TempChar != punctuation) {
				Array.Resize(ref Arguments, Arguments.Length + 1);
				Arguments[arg] += TempChar;
			}
			else {
				arg++;
			}

		}
		return Arguments;
	}

	public static settings GetSettings(string path){
		Console.WriteLine ("Getting settings...");
		string[] settingsArray = File.ReadAllLines (path);
		string[] tempString;
		settings tempSettings = new settings();
		tempSettings.exceptions = new string[0];
		int k = 0;
		for (int i = 0; i < settingsArray.Length; i++) {
			tempString = GetArgs (settingsArray [i], '=');
			switch (tempString [0]) {
			case "cpp":
				tempSettings.cppName = tempString [1];
				break;
			case "header":
				tempSettings.headerName = tempString [1];
				break;
			case "//ignore":
				i++;
				while (settingsArray [i] != "//end") {
					Console.WriteLine ("Gettings exceptions...");
					Array.Resize (ref tempSettings.exceptions, k + 1);
					tempSettings.exceptions [k] = settingsArray [i];
					k++;
					i++;
				}
				break;
			
			}
		}
		return tempSettings;		
	}
}
