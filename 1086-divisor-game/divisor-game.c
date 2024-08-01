void recur(int n, bool *alice){
    if (n == 0){
        return ;
    }
    for (int i=1; i<n; i+=1){
        if (n%i == 0){
            *alice = !(*alice);
            recur(n-i, alice);
            break;
        }
    }
}
bool divisorGame(int n) {
    bool alice = true;
    recur(n, &alice);
    return !alice;
}