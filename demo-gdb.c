
char *t = "\10pse\0r\0dtu\0  ghno\x4e\xc8\x79\xf4\xab\x51\x8a\x10\xf4\xf4\xc4";
int main(void)
{
    char h, m = h = *t++, *x = t + 2 * h, c, i, l = *x, s = 0;
    for (i = 0; i < l; i++) {
	i % 8 ? c <<= 1 : (c = *++x);
	c & 128 && (s += h);
	if (!(h >>= 1) || !t[s + h]) {
	    putchar(t[s]);
	    h = m;
	    s = 0;
	}
    }
    return 0;
}
