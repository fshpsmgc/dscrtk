DM_N DM_N::GCF_NN_N(DM_N op1, DM_N op2) {
    DM_N a = op1;
    DM_N b = op2;
    DM_N c;
    do{
        c->a = MOD_NN_N(a->a, b->a~);
        a = b;
        c = d;
    } while (c);
    return d;
}
