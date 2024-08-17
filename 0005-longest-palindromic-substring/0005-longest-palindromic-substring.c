char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n==1) return s;

    int palmat[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) palmat[i][j] = 1;
            else palmat[i][j] = 0;
        }
    }

    int startidx = 0;
    int maxlen = 1;

    for (int i=0; i<n-1; i++) {
        if (s[i]==s[i+1]) {
            palmat[i][i+1] = 1;
            maxlen= 2;
            startidx = i;
        }
    }

    for (int l=3; l<=n; l++) {
        for (int i=0; i<n-l+1; i++) {
            int j= i+l-1;
            if (s[i]==s[j] && palmat[i+1][j-1]==1) {
                palmat[i][j]=1;
                if (l > maxlen) {
                    maxlen = l;
                    startidx = i;
                }
            }
        }
    }

    char* result = malloc(sizeof(char)*(maxlen+1));
    for (int i=0; i<maxlen; i++) {
        result[i] = s[startidx + i];
    }
    result[maxlen] = '\0';
    return result;
}