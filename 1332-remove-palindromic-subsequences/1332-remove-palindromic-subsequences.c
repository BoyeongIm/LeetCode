int removePalindromeSub(char* s) {
    int n = strlen(s);
    for (int i=0; i<n/2; i++) {
        if (s[i]!=s[n-i-1]) return 2;
    }
    return 1;
}