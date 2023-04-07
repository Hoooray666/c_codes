int myAtoi(char * s){
    double temp = 0;
	int x=1;
    bool flag=true;
	for (int i = 0; s[i] != 0; i++) {
		if (flag&&s[i] == ' ') {
			continue;
		}
        if (flag &&'+' == s[i]) {
			x = 1;
            flag=false;
			continue;
		}
		if (flag &&'-' == s[i]) {
			x = -1;
            flag=false;
			continue;
		}
		if (s[i] < '0' || s[i]>'9') {
			break;
		}
		else {
            flag =false;
			temp = temp * 10 + (s[i] - '0');
			if (temp >=2147483648) {
				return (x == 1 ? 2147483647 : -2147483648);
			}
		}
	}
	temp *= x;
    return (int)temp;
}

