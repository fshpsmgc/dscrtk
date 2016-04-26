DM_N DM_N::MOD_NN_N(DM_N op1, DM_N op2) {
    int N;
    do {
    N++;
    } while(!(op1->a = N*(op2->a)));
    return(SUB_NN_N(op1->a, (N-1)* DIV_NN_N(op1->a, op2->a)));
}
