char *countAndSay(int n){
    if (n == 1) return "1";
    char *s = countAndSay(n-1);
    char *r = (char*)malloc(4466);
    int cnt = 1, idx = 0;
    while(*s != 0) {
        if (*s == *(s+1)) cnt++;
        else {
            r[idx++] = cnt+'0';
            r[idx++] = *s;
            cnt = 1;
        }
        s++;
    }
    r[idx] = 0;
    return r;
}

