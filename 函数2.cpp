int prime(int n);
int chaifen(int n);
void printFactor(int a, int b) {
    if (prime(a)) {
        printf("%d=%d\n", a, a);
    }
    else {
        chaifen(a);
    }
}

int prime(int n) {
    int i;
    int isprime = 1;
    for (i = 1; i < n / 2; i++) {
        if (n % i == 0) {
            isprime = 0;
            break;
        }
    }
    return isprime;
}
int chaifen(int a) {
    int i;
    //     int cnt=0;
    printf("%d=", a);
    for (i = 2; i <= a; i++)
    {
        while (a % i == 0)
        {
            a /= i;
            printf("%d", i);
            if (a > 1) {
                printf("%c", '*');
            }
            else {
                printf("%c", '\n');
            }
        }
    }
}
