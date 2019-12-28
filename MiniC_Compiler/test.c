/*
// lexical error and syntax error
void main(void)
{
    int @a;
    int int;
    a = 1.1;
    if (a = 1)
        a = 2;
    a != 3;
}
*/

/*
// program error
int a;
int a;
 
void fun(int v, int v)
{
    int v;
    int v;
}

void fun(int n)
{
 
}
 
int main(void)
{
    int a;
    int b;
    a = 1;
    b = 1;
    fun(a, b, a);
    fun(c);
    func(a);
    return;
}
*/

/*
 // global array
 int a[10];
 
 void main(void)
 {
    a[1] = 1;
    if (a[1] == 1)
        a[1] = 2;
    else
        a[1] = 3;
 }
 */

/*
// local array
void main(void)
{
    int a;
    int b[5];
    int c;
    int d[10];
    a = 0;
    b[1] = 1;
    d[2] = 2;
    c = d[2];
}
*/

int key;

void keyread(void) {
    key = 10;
}
void print(int x) {
    $0xff00 = x;
}

void delay(void) {
    int c;
    c = 3000000;
    while(c > 0) c = c - 1;
}

int fib(int n) {
    int a;
    int b;
    int tmp;
    int i;
    if (n < 2)
        return n;
    a = 0;
    b = 1;
    tmp = 0;
    i = 2;
    while (i <= n)
    {
        tmp = a + b;
        a = b;
        b = tmp;
        i = i + 1;
    }
    return tmp;
}

void main(void)
{
    int n;
    int v;
    n = 5;
    while(1) {
      //  if(key > 0)
      //      v = fib(key);
        print(v);
        delay();
    }
}

