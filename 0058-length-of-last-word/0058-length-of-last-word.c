int lengthOfLastWord(char* s) {
    int l=strlen(s);
    int length = 0;
    int idx = l-1;

    if (l==1) return 1;

    while (s[idx] == ' ') {
        idx--;
    }

    for (int i=idx; i>=0; i--) {
        if (s[i]!=' ') length++;
        else break;
    }

    return length;
}