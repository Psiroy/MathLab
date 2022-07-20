#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Program Apperance Setting
#define MAIN_TITLE "MathLab"
#define SUB_TITLE "Apollo"
#define VERSION "3.0.20210630"

#define COLOR_CONTROL "F0"
#define COLOR_OUTPUT "\033[35m"
#define COLOR_INPUT "\033[30m"
#define COLOR_ERROR "\033[31m"
//End of Settiing

#define MAX_STR 2048
#define NAME_LEN 64
#define NAMEFILE_LEN 256
//CANCEL ITERATION_MAX
//#define ITERATION_MAX 128
#define POWERMAX 512
#define FUNCVAR_MAX 256

//Variable Identifier
#define VAR_E "e"
#define VAR_PI "pi"
//End of Setting

#define printf printf_s
#define gets gets_s
#define strcpy strcpy_s


#ifdef COLOR_OUTPUT
#ifdef COLOR_INPUT
#define COLOR_IO
#endif
#endif
#ifdef COLOR_IO
#ifdef COLOR_ERROR
#define COLOR_ERRIO
#endif
#endif

struct digital {
	char d;
	struct digital* next;
	struct digital* pre;
};
typedef struct digital digt;
typedef digt* number;
typedef struct {
	number re;
	number im;
	char sgr;
	char sgi;
} vart;
typedef vart* var;
typedef number expr;
struct varcontent {
	var x;
	expr ep;
	int type;
	char name[NAME_LEN];
	struct varcontent* next;
};
typedef struct varcontent varco;
typedef varco* varlist;
struct expnset;
typedef struct expnset* item;
struct explist {
	struct explist *next[2];
	struct explist *pre;
	expr ep;
	var retu;
	int type;
	int prop;
	digt* pre_s;
	digt* pre_e;
	item it;
	item ip;
	char name[NAME_LEN];
	char func[NAME_LEN];
};
typedef struct explist* expn;
typedef number stc;
struct expnset {
	expn en;
	struct expnset* next;
	struct expnset* pre;
	struct expnset* ip;
	var coeff;
};

digt* calldigt(digt* num, char d, char mode);
void changedigt(number num, int n, char d);
void delnum(number n);
int strtonum(char* str, number *pn);
void printnum(number n);
void numtostr(number n, char* str);
void getnum(number *pn);
digt* pre(digt* p);
digt* next(digt* p);
number newnum();
number plusnum(number a, number b);
int compnum(number a, number b);
number num(char *str);
void refreshnum(number n);
digt* topnum(number n);
digt* bottomnum(number n);
digt* locatedigt(number n, int m);
char readdigt(number num, int n);
number minusnum(number a, number b);
number multnum(number a, number b);
number divdnum(number a, number b);
number plusone(number* pn);
number minusone(number* pn);
number adivdnum(number a, number b, int acu);
number anum(number n, int k);
number aplusnum(number a, number b, int acu);
number aminusnum(number a, number b, int acu);
number amultnum(number a, number b, int acu);
void shift(number* pn, int k);
var newvar();
var plus(var a, var b);
var minus(var a, var b);
var op(var x);
void printvar(var x);
var v(char*str);
char* readtillend(char *p, char c[]);
var avar(var x, int acu);
var mult(var a, var b);
number remain(number a, number b);
var conj(var x);
var aplus(var a, var b, int acu);
var aminus(var a, var b, int acu);
var amult(var a, var b, int acu);
var adivd(var a, var b, int acu);
void delvar(var x);
int lennum(number n);
int sumnum(number n);
number copynum(number n);
var copyvar(var x);
var powerint(var x, int n);
var apowerint(var x, int n, int acu);
var _exp(var x, int acu);
var factorial(var x);
int compreal(var a, var b);
int sgnreal(var x);
int iszero(var x);
var _sqrt(var x, int acu);
var ln(var x, int acu);
var _log(var a, var b, int acu);
var power(var a, var b, int acu);
var pi(int acu);
var _sin(var x, int acu);
var _cos(var x, int acu);
var _tan(var x, int acu);
var _sinh(var x, int acu);
var _cosh(var x, int acu);
var _tanh(var x, int acu);
var arctan(var x, int acu);
var arcsin(var x, int acu);
var arccos(var x, int acu);
var rev(var x, int acu);
var e(int acu);
varlist insertvar(var x, char name[], varlist* pvl);
varlist removevar(char name[], varlist vl);
varlist newvarlist();
expr newexpr();
void delvarlist(varlist vl);
void strtoexpr(char* str, expr *pn);
void printexpr(expr n);
void exprtostr(expr n, char *str);
void getexpr(expr *pn);
expr ex(char* str);
expn exn(char*str);
digt* insertdigt(digt* p, char d, char mode);
digt* opp(digt* p);
digt* nextchar(digt* p, char d);
digt* nextcharor(digt* p, char c, char d);
digt* prechar(digt* p, char d);
digt* precharor(digt* p, char c, char d);
int isnumber(digt* p);
int isalpha(digt* p);
int isalphanumber(digt* p);
digt* jumpnumber(digt* p, char mode);
digt* jumpunit(digt* p, char mode);
int issingle(digt* p);
void addforsingle(digt* p);
void addfordouble(digt* p);
void antiaddsingleor(expr ep, char a, char b);
void antiaddsingle(expr ep, char a);
void adddouble(expr ep, char a);
void antiadddouble(expr ep, char a);
void adddoubleor(expr ep, char a, char b);
void initialexpr(expr ep);
expn newexpn();
void defineexpn(expn en, expr ep);
void initialize(expn en);
digt* deldigt(digt* p, char mode);
expr removeoutadd(expr ep);
expr copyexpr(digt* start, digt* end);
void logicalize(expn en, varlist* pvl);
void alllogicalize(expn en, varlist* pvl);
int vartoint(var x);
void calcpower(expn en, varlist* pvl);
void calcapowerint(expn en, varlist vl);
void calcequal(expn en, varlist* pvl);
int istype(expn ep, int n);
void calculate(expn en, varlist* pvl);
void calc(expn en, varlist* pvl);
void delexpn(expn en);
int ispositiveinteger(var x);
int isnegaone(var x);
int isone(var x);
void calchelp(expn en, varlist vl);
var varname(char name[], varlist vl);
expr exprname(char name[], varlist vl);
varlist pvarname(char name[], varlist vl);
varlist pvarnameep(expr ep, varlist vl);
void afcalcd(var f(var, var, int), expn en, varlist vl);
void afcalcdop(var f(var, var, int), expn en, varlist vl);
void afcalc(var f(var, int), expn en, varlist vl);
void fcalc(var f(var), expn en, varlist vl);
void fcalcd(var f(var, var), expn en, varlist vl);
var ce(expr ep, varlist* pvl);
var cea(expr ep, varlist* pvl);
var value(char* str, varlist* pvl);
void calcprint(expn en, varlist vl);
void printvarasfloat(var x);
void printnumasfloat(number n);
void calcremain(expn en, varlist vl);
void calcand(expn en, varlist vl);
void calcor(expn en, varlist vl);
void calcbi(expn en, varlist vl);
void calcsm(expn en, varlist vl);
void calcqu(expn en, varlist vl);
void calcdel(expn en, varlist* pvl);
void calcisdef(expn en, varlist* pvl);
void calcran(expn en, varlist vl);
stc newstc();
digt* nextmark(digt* p);
digt* firstmark(stc st);
void calcmarkexpr(digt* p, varlist* pvl);
var calcmarkexprwithans(digt* p, varlist* pvl);
digt* calcthismark(digt* p, varlist* pvl);
int calcstc(stc st, varlist* pvl);
digt* nextrightba(digt* p);
digt* preleftba(digt* p);
void calcinp(expn en, varlist* pvl);
var realpart(var x);
var imagpart(var x);
var conjc(var x);
void save(expr ep, char* fn);
expr open(char* fn);
void calcrun(expn en, varlist* pvl);
int isnumberzero(number n);
void calcnot(expn en, varlist vl);
int istrue(var x);
int charcheckforexpr(expr ep);
var vexp(expr ep);
number numexp(expr ep);
int istheexprnumber(expr ep);
int istheexprname(expr ep);
expr getline();
void printerr(int code);
int isoperator(digt* p);
int isdouble(digt* p);
int isoperative(digt* p);
void insertexpr(expr ep, char name[], varlist* pvl);
int issingleoperator(digt* p);
int isdoubleoperator(digt* p);
int getyesornot();
expr replace(expr ep, expr before, expr after);
int istheexpr(digt* p, expr ep);
digt* jumpnextchar(digt* p, char d);
var _ceil(var x);
var _floor(var x);
var _abs(var x, int acu);
number _rand(number inf, number sup);
void calcstrplus(expn en, varlist vl);
void calcstrreplace(expn en, varlist vl);
void calctoexp(expn en, varlist* pvl);
void calctostr(expn en, varlist vl);
void calcstrcopy(expn en, varlist vl);
int compexpr(expr a, expr b);
void calcstrcmp(expn en, varlist vl);
void calcstrsearch(expn en, varlist vl);
void readhead(varlist* pvl);
void calcstrlen(expn en, varlist vl);
void calcsum(expn en, varlist* pvl);
void calcprod(expn en, varlist* pvl);
void calcsave(expn en, varlist vl);
void calcopen(expn en, varlist vl);
void calcfiledel(expn en, varlist vl);
void calccmd(expn en, varlist vl);
void calcpr(expn en, varlist vl);
int removeoutba(expr* ep);
void printans(varlist vl);
int oppcheckoutba(expr p);
int isstcsym(digt* p);
void resetexpn(expn en);
expn definebycopy(expn en, digt* p, digt* q);
expr copyoriginal(expn en);
void decoration(expn en);
int getprior(expn en);
expr expnum(number n);
expr evar(var x);
void restorecopy(expn enn, expr ep);
expr addoutba(expr ep, char a, char b);
item newitemset();
item insertitem(item p, expn en, var coeff);
item bottomitem(item it);
item topitem(item it);
void delitemset(item n);
item delitem(item p, char mode);
void addtoitemset(item n, expn en, var coeff, char mode);
void casplus(expn en, varlist vl);
expr expitemset(item n);
void casplussingle(expn en);
void casplusdouble(expn en);
expr expvarforexpitemset(var x, char item, char head);
void firstaddtoitemset(item n, expn en, char sgn);
void casprod(expn en, varlist* pvl);
void casproduct(expn en, varlist* pvl, int acu);
int addtoproditemset(item n, expn en, var coeff, char mode, int acu, varlist* pvl);
int firstaddtoproditemset(item n, expn en, char sgn, int acu, varlist* pvl);
void expproditemset(item n, expr* num, expr* exp);
expr expvarforexpproditemset(var x, char bottom);
item newproditemset();
digt* nextqu(digt* p);
digt* prequ(digt* p);
expr removeoutqu(expr ep);
int isitemsameclass(item a, item b);
void additemtoitemset(item n, item q);
int issameclass(expn a, expn b);
item copyitemset(item p);
int casproplussimple(item n, var x, char mode, int acu);
void casproplussingle(item n, item p, varlist* pvl);
int casproplusip(item n, item p, char mode, int acu, varlist* pvl);
int casproplusep(item n, expn en, var coeff, char mode, int acu, varlist* pvl);
item newitem();
void neutralizeitemset(item n);
void addpluseptoproditemset(item ip, expn en, var coeff, char mode, int acu, varlist* pvl);
void addpluseptoitemset(item n, expn en, var coeff, char mode);
expn copyexpn(expn en);
void casdiff(expn en, varlist* pvl);
void replaceexpn(expn en, expn enp);
expn casdif(expn en, char* var, varlist* pvl);
expn casplu(expn a, expn b, varlist vl);
expn casminus(expn a, expn b, varlist vl);
expn caspro(expn a, expn b, varlist* pvl);
expn casdifunc(expn en, char mode, varlist* pvl);
void calcname(expn en, varlist* pvl);
item casdifit(item it, char* var, varlist* pvl);
item casdifip(item ip, char* var, varlist* pvl);
expn enep(expr ep, varlist* pvl);
expr connect(expr a, expr b);
int propitem(item n);
int propproditem(item n);
int isepthevar(expr ep, char* va);
void calcsqrt(expn en, varlist* pvl);
item copyitemset_id(item p);
void calcln(expn en, varlist vl);
int compexpr_sans(expr a, expr b);
expn envar(var x);
void calcexp(expn en, varlist vl);
expn caspowerint(expn en, int n, varlist* pvl);
void calcdfdx(expn en, varlist* pvl);
expn arraynext(expn en);
int lenarray(expn en);
void calcfunc(varlist p, expn en, varlist* pvl);
void calcarraylen(expn en, varlist vl);
var intvar(int k);
void calcarraylen(expn en, varlist vl);
int isdfdx(expn en, varlist vl);
void dispvarlist(varlist vl);
void calcspace(expn en, varlist* pvl);
void alldecoration(expn en);

//CANCEL ITERATION_MAX
//static int iteration_number;

void main(int argc,char *argv[]) {
	varlist vl = newvarlist();
	stc st;
	system("title "MAIN_TITLE);
#ifdef COLOR_CONTROL
	system("color "COLOR_CONTROL);
#endif
	if (argc < 2) {
//		system("mode con cols=64 lines=24");
//		printf(MAIN_TITLE" [Version "VERSION"]\n\n");
		readhead(&vl);
#ifdef COLOR_IO
		printf(COLOR_OUTPUT);
		while (1) {
			putchar('>');
			printf(COLOR_INPUT);
			st = getline();
			printf(COLOR_OUTPUT);
			if(calcstc(st, &vl)) printans(vl);
			delnum(st);
		}
#else
		while (1) {
			putchar('>');
			st = getline();
			if (calcstc(st, &vl)) printans(vl);
			delnum(st);
		}
#endif
	}
	else {
#ifdef COLOR_IO
		printf(COLOR_OUTPUT);
#endif
		readhead(&vl);
		st = open(argv[1]);
		if (calcstc(st, &vl)) printans(vl);
		delnum(st);
	}
}
digt* calldigt(digt* num, char d, char mode) {
	digt* dig;
	if ((mode != 'n'&&mode != 'p'&&mode != 0)) return NULL;
	dig = (digt*)malloc(sizeof(digt));
	if (dig == NULL) {
		printerr(100);
		system("pause");
		exit(0);
	}
	dig->d = d;
	if (mode == 0) {
		dig->pre = NULL;
		dig->next = NULL;
	}
	if (mode == 'n') {
		dig->pre = num;
		dig->next = NULL;
		num->next = dig;
	}
	if (mode == 'p') {
		dig->pre = NULL;
		dig->next = num;
		num->pre = dig;
	}
	return dig;
}
void changedigt(number num, int n, char d) {
	digt* p = locatedigt(num, n);
	if (p == NULL) return;
	p->d = d;
}
void delnum(number n) {
	digt *p, *q;
	if (n == NULL) return;
	p = n->next;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	p = n->pre;
	while (p != NULL) {
		q = p->pre;
		free(p);
		p = q;
	}
	free(n);
}
int strtonum(char* str, number *pn) {
	int ind = 0, count = 0;
	digt* p;
	char* check;
	for (check = str; *check; check++) {
		if (*check == '.') count++;
		if ((*check > '9' || *check < '0') && *check != '.') {
			printerr(101);
			return 0;
		}
	}
	if (count > 1) {
		printerr(102);
		return 0;
	}
	delnum(*pn);
	*pn = newnum();
	p = *pn;
	if (*str == '.') {
		p->d = 0;
		ind = 1;
	}
	else {
		p->d = *str - '0';
	}
	str++;
	while (*str) {
		if (*str == '.') {
			*pn = p;
			ind = 1;
		}
		else {
			p = calldigt(p, *str - '0', 'p');
		}
		str++;
	}
	if (ind == 0) *pn = p;
	return 1;
}
void printnum(number n) {
	digt* p = n;
	int k = 0;
	if (n == NULL) return;
	while ((p->next) != NULL) p = p->next;
	while (p != NULL) {
		if (k == 1) {
			putchar(p->d + '0');
		}
		else {
			if (p->d != 0 || p == n) {
				putchar(p->d + '0');
				k = 1;
			}
		}
		if (p == n && p->pre != NULL) putchar('.');
		p = p->pre;
	}
}
void printnumasfloat(number n) {
	number zero;
	int k = 0;
	if (n == NULL) return;
	zero = num("0");
	if (compnum(n, zero) == 0) {
		printnum(n);
		delnum(zero);
		return;
	}
	refreshnum(n);
	if (topnum(n)->d == 0) {
		while (n->d == 0) {
			shift(&n, 1);
			k--;
		}
	}
	else {
		while (n->next!=NULL) {
			shift(&n, -1);
			k++;
		}
	}
	printnum(n);
	if (k != 0) {
		putchar('E');
		printf("%d", k);
	}
	delnum(zero);
}
void numtostr(number n, char* str) {
	int k = 0;
	digt* p = n;
	while ((p->next) != NULL) p = p->next;
	while (p != NULL) {
		if (k == 1) {
			*str = p->d + '0';
		}
		else {
			if (p->d != 0) {
				*str = p->d + '0';
				k = 1;
			}
		}
		if (p == n&&p->pre != NULL) *(++str) = '.';
		p = p->pre;
		str++;
	}
	*str = '\0';
}
void getnum(number *pn) {
	char str[MAX_STR];
	gets(str, MAX_STR);
	strtonum(str, pn);
}
digt* pre(digt* p) {
	if (p->pre == NULL) p = calldigt(p, 0, 'p');
	else p = p->pre;
	return p;
}
digt* next(digt* p) {
	if (p->next == NULL) p = calldigt(p, 0, 'n');
	else p = p->next;
	return p;
}
number newnum() {
	return calldigt(NULL, 0, 0);
}
number plusnum(number a, number b) {
	char k = 0, r;
	number ha = a, hb = b;
	number ans = newnum();
	while (a->pre != NULL || b->pre != NULL) {
		a = pre(a);
		b = pre(b);
	}
	while (a->next != NULL || b->next != NULL) {
		r = a->d + b->d + k;
		if (r > 9) {
			k = 1;
			ans->d = r - 10;
		}
		else {
			k = 0;
			ans->d = r;
		}
		ans = next(ans); a = next(a); b = next(b);
	}
	r = a->d + b->d + k;
	if (r > 9) {
		k = 1;
		ans->d = r - 10;
		next(ans)->d = 1;
	}
	else {
		k = 0;
		ans->d = r;
	}
	if (a != NULL) {
		while (a != ha) {
			ans = ans->pre;
			a = a->pre;
		}
	}
	else {
		while (b != hb) {
			ans = ans->pre;
			b = b->pre;
		}
	}
	return ans;
}
int compnum(number a, number b) {
	while (a->next != NULL || b->next != NULL) {
		a = next(a);
		b = next(b);
	}
	while (a->pre != NULL || b->pre != NULL) {
		if (a->d > b->d) return 1;
		if (a->d < b->d) return -1;
		a = pre(a); b = pre(b);
	}
	if (a->d > b->d) return 1;
	if (a->d < b->d) return -1;
	return 0;
}
int compexpr(expr a, expr b) {
	if (a == NULL && b == NULL) return 1;
	if ((a == NULL && b != NULL) || (a != NULL && b == NULL)) return 0;
	while (a->next != NULL && b->next != NULL) {
		if (a->d != b->d) return 0;
		a = a->next; b = b->next;
	}
	if (a->d != b->d) return 0;
	if (!(a->next == NULL&&b->next == NULL)) return 0;
	return 1;
}
number num(char *str) {
	number n = newnum();
	strtonum(str, &n);
	return n;
}
void refreshnum(number n) {
	digt *p, *q;
	p = topnum(n);
	while (p->d == 0 && p->pre != NULL&&p != n) {
		q = p->pre;
		free(p);
		p = q;
	}
	p->next = NULL;
	p = bottomnum(n);
	while (p->d == 0 && p->next != NULL&&p != n) {
		q = p->next;
		free(p);
		p = q;
	}
	p->pre = NULL;
}
digt* topnum(number n) {
	while ((n->next) != NULL) n = n->next;
	return n;
}
digt* bottomnum(number n) {
	while ((n->pre) != NULL) n = n->pre;
	return n;
}
digt* locatedigt(number num, int n) {
	digt* p = num;
	if (num == NULL) return NULL;
	if (n >= 0) {
		for (; n != 0; n--) {
			if (p->next == NULL) calldigt(p, 0, 'n');
			p = p->next;
		}
		return p;
	}
	else {
		for (; n != 0; n++) {
			if (p->pre == NULL) calldigt(p, 0, 'p');
			p = p->pre;
		}
		return p;
	}
}
char readdigt(number num, int n) {
	digt* p = locatedigt(num, n);
	if (p == NULL) return 0;
	return p->d;
}
number minusnum(number a, number b) {
	char k = 0, r;
	number ha, hb;
	number temp;
	number ans = newnum();
	int l = compnum(a, b);
	if (l == 0) return ans;
	if (l < 0) {
		temp = a; a = b; b = temp;
	}
	ha = a; hb = b;
	while (a->pre != NULL || b->pre != NULL) {
		a = pre(a);
		b = pre(b);
	}
	while (a->next != NULL || b->next != NULL) {
		r = a->d - b->d - k;
		if (r < 0) {
			k = 1;
			ans->d = r + 10;
		}
		else {
			k = 0;
			ans->d = r;
		}
		ans = next(ans); a = next(a); b = next(b);
	}
	r = a->d - b->d - k;
	ans->d = r;
	if (a != NULL) {
		while (a != ha) {
			ans = ans->pre;
			a = a->pre;
		}
	}
	else {
		while (b != hb) {
			ans = ans->pre;
			b = b->pre;
		}
	}
	return ans;
}
number multnum(number a, number b) {
	number s = newnum(), t[10], p, temp;
	int k = 0, i, m = 0;
	t[0] = newnum();
	if (sumnum(a) < sumnum(b)) {
		temp = a; a = b; b = temp;
	}
	while ((b->pre) != NULL) {
		b = b->pre;
		k--;
	}
	while (b != NULL) {
		if (b->d > m) {
			for (i = m; i < b->d; i++) t[i + 1] = plusnum(t[i], a);
			m = b->d;
		}
		p = t[b->d];
		shift(&p, k);
		temp = plusnum(s, p);
		refreshnum(t[b->d]);
		delnum(s);
		s = temp;
		b = b->next;
		k++;
	}
	for (i = 0; i <= m; i++) delnum(t[i]);
	return s;
}
number divdnum(number a, number b) {
	number r, s = newnum(), t;
	if (compnum(b, s) == 0) {
		delnum(s);
		printerr(1);
		return NULL;
	}
	delnum(s);
	s = copynum(b);
	r = newnum();
	while (compnum(a, s) >= 0) {
		t = plusnum(s, b);
		delnum(s);
		s = t;
		plusone(&r);
	}
	delnum(s);
	return r;
}
number plusone(number* pn) {
	number one, temp;
	one = num("1");
	temp = plusnum(*pn, one);
	delnum(one);
	*pn = temp;
	return *pn;
}
number minusone(number* pn) {
	number one, temp;
	one = num("1");
	temp = minusnum(*pn, one);
	delnum(one);
	*pn = temp;
	return *pn;
}
number adivdnum(number a, number b, int acu) {
	number ans = newnum();
	number r = NULL, s = NULL, t = NULL, u = NULL;
	number x, y, zero;
	int k = 0, i;
	if (compnum(b, ans) == 0) {
		delnum(ans);
		printerr(2);
		return NULL;
	}
	x = copynum(a);
	y = copynum(b);
	zero = newnum();
	while (compnum(x, y) >= 0) {
		shift(&y, 1);
		k++;
	}
	for (i = 0; i < acu; i++) {
		shift(&y, -1);
		k--;
		r = divdnum(x, y);
		s = multnum(y, r);
		t = x;
		x = minusnum(x, s);
		shift(&r, k);
		u = ans;
		ans = plusnum(ans, r);
		delnum(r);
		delnum(s);
		delnum(t);
		delnum(u);
		if (compnum(x, zero) == 0) break;
	}
	delnum(y);
	return ans;
}
void shift(number* pn, int k) {
	int i;
	if (k >= 0) for (i = 0; i < k; i++) *pn = pre(*pn);
	else for (i = 0; i < -k; i++) *pn = next(*pn);
}
number anum(number n, int k) {
	digt* p = n, *q, *r;
	int i, l = 0, m;
	k--;
	refreshnum(n);
	while (p->next != NULL) {
		p = p->next;
		l++;
	}
	for (i = 0; i < k; i++) p = pre(p);
	m = k > l ? k : l;
	for (i = k; i < m; i++) {
		p = pre(p);
		p->d = 0;
	}
	q = p->pre;
	p->pre = NULL;
	while (q != NULL) {
		r = q->pre;
		free(q);
		q = r;
	}
	return n;
}
number aplusnum(number a, number b, int acu) {
	number ans;
	anum(a, acu);
	anum(b, acu);
	ans = plusnum(a, b);
	anum(ans, acu);
	return ans;
}
number aminusnum(number a, number b, int acu) {
	number ans;
	anum(a, acu);
	anum(b, acu);
	ans = minusnum(a, b);
	anum(ans, acu);
	return ans;
}
number amultnum(number a, number b, int acu) {
	number s = newnum(), t[10], p, temp;
	int k = 0, i, m = 0;
	t[0] = newnum();
	a = anum(a, acu);
	b = anum(b, acu);
	if (sumnum(a) < sumnum(b)) {
		temp = a; a = b; b = temp;
	}
	while ((b->pre) != NULL) {
		b = b->pre;
		k--;
	}
	while (b != NULL) {
		if (b->d > m) {
			for (i = m; i < b->d; i++) t[i + 1] = plusnum(t[i], a);
			m = b->d;
		}
		p = t[b->d];
		shift(&p, k);
		temp = plusnum(s, p);
		refreshnum(t[b->d]);
		delnum(s);
		s = temp;
		b = b->next;
		k++;
	}
	anum(s, acu);
	for (i = 0; i <= m; i++) delnum(t[i]);
	return s;
}
int sumnum(number n) {
	int x, y;
	digt *p, *q;
	x = y = 0;
	p = q = n;
	while ((p->next) != NULL) {
		p = p->next;
		x += p->d;
	}
	while ((q->pre) != NULL) {
		q = q->pre;
		y += q->d;
	}
	return x + y + n->d;
}
int lennum(number n) {
	int x, y;
	digt *p, *q;
	if (n == NULL) return 0;
	x = y = 0;
	p = q = n;
	while ((p->next) != NULL) {
		p = p->next;
		x++;
	}
	while ((q->pre) != NULL) {
		q = q->pre;
		y++;
	}
	return x + y + 1;
}
number copynum(number n) {
	number ans;
	digt *p, *q;
	if (n == NULL) return NULL;
	ans = newnum();
	p = ans; q = n;
	p->d = q->d;
	while (q->next != NULL) {
		q = q->next;
		p = calldigt(p, q->d, 'n');
	}
	p = ans; q = n;
	while (q->pre != NULL) {
		q = q->pre;
		p = calldigt(p, q->d, 'p');
	}
	return ans;
}
number remain(number a, number b) {
	number s = newnum(), t;
	if (compnum(b, s) == 0) {
		delnum(s);
		printerr(3);
		return NULL;
	}
	delnum(s);
	s = copynum(a);
	while (compnum(s, b) >= 0) {
		t = minusnum(s, b);
		delnum(s);
		s = t;
	}
	return s;
}
char* readtillend(char *p, char c[]) {
	while ((*p >= '0'&&*p <= '9') || *p == '.') {
		*c = *p;
		c++; p++;
	}
	*c = 0;
	return p;
}
int isnumberzero(number n) {
	number zero;
	if (n == NULL) return 0;
	zero = newnum();
	if (compnum(n, zero) == 0) {
		delnum(zero);
		return 1;
	}
	else {
		delnum(zero);
		return 0;
	}
}
var newvar() {
	var pv;
	pv = (vart*)malloc(sizeof(vart));
	if (pv == NULL) {
		printerr(200);
		system("pause");
		exit(0);
	}
	pv->re = newnum();
	pv->im = newnum();
	pv->sgr = 1;
	pv->sgi = 1;
	return pv;
}
var plus(var a, var b) {
	var ans = newvar();
	if (a->sgr*b->sgr > 0) {
		ans->sgr = a->sgr;
		ans->re = plusnum(a->re, b->re);
	}
	else {
		if (compnum(a->re, b->re) >= 0) ans->sgr = a->sgr;
		else ans->sgr = b->sgr;
		ans->re = minusnum(a->re, b->re);
	}
	if (a->sgi*b->sgi > 0) {
		ans->sgi = a->sgi;
		ans->im = plusnum(a->im, b->im);
	}
	else {
		if (compnum(a->im, b->im) >= 0) ans->sgi = a->sgi;
		else ans->sgi = b->sgi;
		ans->im = minusnum(a->im, b->im);
	}
	return ans;
}
var op(var x) {
	x->sgr = -x->sgr;
	x->sgi = -x->sgi;
	return x;
}
var minus(var a, var b) {
	var ans;
	ans = plus(a, op(b));
	op(b);
	return ans;
}
void printvar(var x) {
	number one = num("1"), zero = num("0");
	int r, i;
	if (x == NULL) {
		delnum(one);
		delnum(zero);
		return;
	}
	r = compnum(x->re, zero);
	i = compnum(x->im, zero);
	if (r) {
		if (x->sgr == -1) putchar('-');
		printnum(x->re);
	}
	if (i) {
		if (x->sgi == -1) putchar('-');
		else if (r) putchar('+');
		if (compnum(x->im, one)) printnum(x->im);
		putchar('i');
	}
	if (r == 0 && i == 0) putchar('0');
	delnum(one);
	delnum(zero);
}
void printvarasfloat(var x) {
	number one = num("1"), zero = num("0");
	int r, i;
	if (x == NULL) {
		delnum(one);
		delnum(zero);
		return;
	}
	r = compnum(x->re, zero);
	i = compnum(x->im, zero);
	if (r) {
		if (x->sgr == -1) putchar('-');
		printnumasfloat(x->re);
	}
	if (i) {
		if (x->sgi == -1) putchar('-');
		else if (r) putchar('+');
		if (compnum(x->im, one)) printnumasfloat(x->im);
		putchar('i');
	}
	if (r == 0 && i == 0) putchar('0');
	delnum(one);
	delnum(zero);
}
var v(char*str) {
	int i;
	char sg;
	char *p = str, *temp;
	char c[2][MAX_STR];
	var x = newvar();
	for (i = 0; i < 2; i++) {
		sg = 1;
		if (*p == '+' || *p == '-') {
			if (*p == '-') sg = -1;
			p++;
		}
		temp = p;
		p = readtillend(p, c[i]);
		if (p == temp) {
			c[i][0] = '1';
			c[i][1] = 0;
		}
		if (*p == 'i') {
			x->sgi = sg;
			x->im = num(c[i]);
			p++;
		}
		else {
			x->sgr = sg;
			x->re = num(c[i]);
		}
		if (*p == 0) return x;
	}
	return x;
}
var avar(var x, int acu) {
	if (x == NULL) return NULL;
	anum(x->re, acu);
	anum(x->im, acu);
	return x;
}
var mult(var a, var b) {
	var ans, t1 = newvar(), t2 = newvar();
	number s1, s2, s3, s4;
	s1 = multnum(a->re, b->re);
	s2 = multnum(a->im, b->im);
	s3 = multnum(a->re, b->im);
	s4 = multnum(a->im, b->re);
	t1->re = s1;
	t1->im = s3;
	t2->re = s2;
	t2->im = s4;
	t1->sgr = a->sgr*b->sgr;
	t1->sgi = a->sgr*b->sgi;
	t2->sgr = -a->sgi*b->sgi;
	t2->sgi = a->sgi*b->sgr;
	ans = plus(t1, t2);
	delvar(t1);
	delvar(t2);
	return ans;
}
void delvar(var x) {
	if (x == NULL) return;
	delnum(x->re);
	delnum(x->im);
	free(x);
}
var conj(var x) {
	x->sgi = -x->sgi;
	return x;
}
var aplus(var a, var b, int acu) {
	avar(a, acu);
	avar(b, acu);
	return avar(plus(a, b), acu);
}
var aminus(var a, var b, int acu) {
	avar(a, acu);
	avar(b, acu);
	return minus(a, b);
}
var amult(var a, var b, int acu) {
	var ans, t1 = newvar(), t2 = newvar();
	number s1, s2, s3, s4;
	s1 = amultnum(a->re, b->re, acu);
	s2 = amultnum(a->im, b->im, acu);
	s3 = amultnum(a->re, b->im, acu);
	s4 = amultnum(a->im, b->re, acu);
	t1->re = s1;
	t1->im = s3;
	t2->re = s2;
	t2->im = s4;
	t1->sgr = a->sgr*b->sgr;
	t1->sgi = a->sgr*b->sgi;
	t2->sgr = -a->sgi*b->sgi;
	t2->sgi = a->sgi*b->sgr;
	ans = aplus(t1, t2, acu);
	delvar(t1);
	delvar(t2);
	return ans;
}
var adivd(var a, var b, int acu) {
	var ans;
	number x, y, s, p, q, r, i, zero = newnum();
	if (compnum(b->re, zero) == 0 && compnum(b->im, zero) == 0) {
		printerr(4);
		delnum(zero);
		return NULL;
	}
	r = copynum(b->re);
	i = copynum(b->im);
	x = multnum(b->re, r);
	y = multnum(b->im, i);
	s = plusnum(x, y);
	ans = mult(a, conj(b));
	p = adivdnum(ans->re, s, acu);
	q = adivdnum(ans->im, s, acu);
	delnum(ans->re);
	delnum(ans->im);
	ans->re = p;
	ans->im = q;
	delnum(x); delnum(y); delnum(s); delnum(r); delnum(i); delnum(zero);
	conj(b);
	return ans;
}
var copyvar(var x) {
	var ans;
	if (x == NULL) return NULL;
	ans = newvar();
	ans->re = copynum(x->re);
	ans->im = copynum(x->im);
	ans->sgr = x->sgr;
	ans->sgi = x->sgi;
	return ans;
}
var powerint(var x, int n) {
	int m;
	var temp, s, t;
	if (n == 1) return copyvar(x);
	if (n == 0) return v("1");
	if (n % 2 == 0) {
		temp = powerint(x, n / 2);
		s = mult(temp, temp);
		delvar(temp);
		return s;
	}
	else {
		m = n - n / 2;
		temp = powerint(x, n / 2);
		t = powerint(x, m);
		s = mult(temp, t);
		delvar(temp);
		delvar(t);
		return s;
	}
}
var apowerint(var x, int n, int acu) {
	int m;
	var temp, s, t;
	if (n == 1) return copyvar(x);
	if (n == 0) return v("1");
	if (n % 2 == 0) {
		temp = apowerint(x, n / 2, acu);
		s = mult(temp, temp);
		delvar(temp);
		return s;
	}
	else {
		m = n - n / 2;
		temp = apowerint(x, n / 2, acu);
		t = apowerint(x, m, acu);
		s = mult(temp, t);
		delvar(temp);
		delvar(t);
		return s;
	}
}
static var _exps(var x, int acu) {
	var f = v("1"), p = v("1"), k = newvar(), ans = v("1");
	var s, t;
	while (1) {
		t = p;
		p = mult(p, x);
		delvar(t);
		plusone(&k->re);
		t = f;
		f = mult(f, k);
		delvar(t);
		s = adivd(p, f, acu + 1);
		if (iszero(s) == 1) {
			delvar(s);
			break;
		}
		t = ans;
		ans = plus(ans, s);
		delvar(s);
		delvar(t);
	}
	delvar(f); delvar(p); delvar(k);
	ans = avar(ans, acu);
	return ans;
}
var _exp(var x, int acu) {
	number sup = num("4");
	var two = v("2"), hf = NULL, ans;
	if (compnum(x->re, sup) > 0|| compnum(x->im, sup) > 0) {
		hf = adivd(x, two, acu + 1);
		ans = avar(powerint(_exp(hf, acu + 1),2), acu);
		delvar(hf);
	}
	else ans = _exps(x, acu);
	delnum(sup); delvar(two);
	return ans;
}
var factorial(var x) {
	var ans = v("1"), temp, one = v("1"), p = copyvar(x);
	while (sgnreal(p) == 1) {
		temp = ans;
		ans = mult(ans, p);
		delvar(temp);
		temp = p;
		p = minus(p, one);
		delvar(temp);
	}
	delvar(p);
	delvar(one);
	return ans;
}
int compreal(var a, var b) {
	int s, t;
	number zero = newnum();
	s = a->sgr;
	t = b->sgr;
	if (compnum(a->re, zero) == 0) s = 0;
	if (compnum(b->re, zero) == 0) t = 0;
	delnum(zero);
	if (s > t) return 1;
	if (s < t) return -1;
	if (s == 0) return 0;
	if (s == 1) return compnum(a->re, b->re);
	else return -compnum(a->re, b->re);
}
int sgnreal(var x) {
	int ans;
	var zero = newvar();
	ans = compreal(x, zero);
	delvar(zero);
	return ans;
}
int iszero(var x) {
	int k = 0;
	number zero = newnum();
	if (compnum(x->re, zero) == 0 && compnum(x->im, zero) == 0) k = 1;
	delnum(zero);
	return k;
}
int istrue(var x) {
	int k = 1;
	number zero;
	if (x == NULL) return k;
	zero = newnum();
	if (compnum(x->re, zero) == 0) k = 0;
	delnum(zero);
	return k;
}
static var _sqrts(var x, int acu) {
	var a = newvar(), s, t, two = v("2"), pre, d, xr;
	a->re = copynum(x->re);
	pre = copyvar(a);
	xr = copyvar(a);
	while (1) {
		s = adivd(xr, a, acu + 1);
		t = plus(s, a);
		delvar(s);
		s = adivd(t, two, acu + 1);
		d = minus(s, pre);
		if (iszero(d) == 1) {
			delvar(pre);
			delvar(d);
			delvar(t);
			delvar(a);
			a = s;
			break;
		}
		delvar(d);
		delvar(pre);
		pre = copyvar(s);
		delvar(t);
		delvar(a);
		a = s;
	}
	delvar(two);
	delvar(xr);
	a = avar(a, acu);
	return a;
}
var _sqrt(var x, int acu) {
	number zero;
	var i, temp, ans;
	if (x == NULL) return NULL;
	zero = newnum();
	if (compnum(x->im, zero)!=0) {
		delnum(zero);
		printerr(5);
		return NULL;
	}
	if (compnum(x->re, zero) == 0) {
		delnum(zero);
		return newvar();
	}
	delnum(zero);
	if (x->sgr > 0) return _sqrts(x, acu);
	else {
		i = v("i");
		temp = _sqrts(x, acu);
		ans = mult(temp, i);
		delvar(i);
		delvar(temp);
		return ans;
	}
}
static var lnrs(var x, int acu) {
	var y, f = v("1"), p = v("2"), ans, one = v("1"), two = v("2");
	var s, t;
	s = plus(x, one);
	t = minus(x, one);
	y = adivd(t, s, acu + 1);
	delvar(s);
	delvar(t);
	s = mult(p, y);
	delvar(p);
	p = s;
	s = copyvar(y);
	t = mult(y, s);
	delvar(s);
	delvar(y);
	y = t;
	ans = adivd(p, f, acu + 1);
	while (1) {
		t = p;
		p = mult(p, y);
		delvar(t);
		t = f;
		f = plus(f, two);
		delvar(t);
		s = adivd(p, f, acu + 1);
		if (iszero(s) == 1) {
			delvar(s);
			break;
		}
		t = ans;
		ans = plus(ans, s);
		delvar(s);
		delvar(t);
	}
	delvar(f); delvar(p); delvar(one); delvar(two);
	ans = avar(ans, acu);
	return ans;
}
static var lnr(var x, int acu) {
	number sup = num("4"), inf = num("0.25"), zero = newnum();
	var two = v("2"), sq=NULL, ans;
	if (compnum(x->im, zero) != 0 || compnum(x->re, zero) == 0 || x->sgr < 0) {
		delnum(sup); delnum(inf); delvar(two); delnum(zero);
		printerr(6);
		return NULL;
	}
	if (compnum(x->re, sup) > 0 || compnum(x->re, inf) < 0) {
		sq = _sqrt(x, acu + 1);
		ans = avar(mult(lnr(sq, acu+1), two),acu);
	}
	else ans = lnrs(x, acu);
	delnum(sup); delnum(inf); delvar(two); delvar(sq); delnum(zero);
	return ans;
}
var ln(var x, int acu) {
	return lnr(x, acu);
}
var _log(var a, var b, int acu) {
	var ans, s, t;
	s = ln(a, acu + 1);
	t = ln(b, acu + 1);
	if (s == NULL || t == NULL) {
		delvar(s);
		delvar(t);
		return NULL;
	}
	ans = adivd(t, s, acu + 1);
	delvar(s);
	delvar(t);
	ans = avar(ans, acu);
	return ans;
}
var power(var a, var b, int acu) {
	var ans, s, t;
	s = ln(a, acu + 1);
	if (s == NULL) return NULL;
	t = mult(s, b);
	ans = _exp(t, acu + 1);
	delvar(s); delvar(t);
	ans = avar(ans, acu);
	return ans;
}
var pi(int acu) {
	var four = v("4"), p = v("5"), q = v("239"), t, ans;
	t = p;
	p = rev(p, acu + 1);
	delvar(t);
	t = q;
	q = rev(q, acu + 1);
	delvar(t);
	t = p;
	p = arctan(p, acu + 1);
	delvar(t);
	t = q;
	q = arctan(q, acu + 1);
	delvar(t);
	t = p;
	p = mult(p, four);
	delvar(t);
	ans = minus(p, q);
	t = ans;
	ans = mult(ans, four);
	delvar(t);
	delvar(p);
	delvar(q);
	delvar(four);
	ans = avar(ans, acu);
	return ans;
}
static var _sins(var x, int acu) {
	var y, f = v("1"), p, ans, k = v("1");
	var s, t;
	p = copyvar(x);
	y = mult(x, p);
	ans = copyvar(x);
	while (1) {
		t = p;
		p = mult(p, y);
		delvar(t);
		plusone(&k->re);
		t = f;
		f = mult(f, k);
		delvar(t);
		plusone(&k->re);
		t = f;
		f = mult(f, k);
		delvar(t);
		op(f);
		s = adivd(p, f, acu + 1);
		if (iszero(s) == 1) {
			delvar(s);
			break;
		}
		t = ans;
		ans = plus(ans, s);
		delvar(s);
		delvar(t);
	}
	delvar(f); delvar(p); delvar(k);
	ans = avar(ans, acu);
	return ans;
}
var _sin(var x, int acu) {
	number sup = num("4"), temp;
	var y, ans, p, q, t, two;
	if (compnum(x->re, sup) < 0 && compnum(x->im, sup) < 0) {
		delnum(sup);
		return _sins(x, acu);
	}
	two = v("2");
	y = copyvar(x);
	p = pi(acu+1);
	t = mult(p, two);
	delvar(p);
	p = t;
	q = copyvar(p);
	temp = q->re;
	q->re = q->im;
	q->im = temp;
	q->sgi = 1;
	while(compnum(y->re, sup) > 0) {
		if(y->sgr>0) t = minus(y, p);
		else t = plus(y, p);
		delvar(y);
		y = t;
	}
	while (compnum(y->im, sup) > 0) {
		if (y->sgi>0) t = minus(y, q);
		else t = plus(y, q);
		delvar(y);
		y = t;
	}
	ans = _sins(y, acu);
	delnum(sup); delvar(y); delvar(p); delvar(q);
	return ans;
}
static var _coss(var x, int acu) {
	var y, f = v("1"), p, ans, k = v("0");
	var s, t;
	p = copyvar(x);
	y = mult(x, p);
	delvar(p);
	p = v("1");
	ans = v("1");
	while (1) {
		t = p;
		p = mult(p, y);
		delvar(t);
		plusone(&k->re);
		t = f;
		f = mult(f, k);
		delvar(t);
		plusone(&k->re);
		t = f;
		f = mult(f, k);
		delvar(t);
		op(f);
		s = adivd(p, f, acu + 1);
		if (iszero(s) == 1) {
			delvar(s);
			break;
		}
		t = ans;
		ans = plus(ans, s);
		delvar(s);
		delvar(t);
	}
	delvar(f); delvar(p); delvar(k);
	ans = avar(ans, acu);
	return ans;
}
var _cos(var x, int acu) {
	number sup = num("4"), temp;
	var y, ans, p, q, t, two;
	if (compnum(x->re, sup) < 0 && compnum(x->im, sup) < 0) {
		delnum(sup);
		return _coss(x, acu);
	}
	two = v("2");
	y = copyvar(x);
	p = pi(acu + 1);
	t = mult(p, two);
	delvar(p);
	p = t;
	q = copyvar(p);
	temp = q->re;
	q->re = q->im;
	q->im = temp;
	q->sgi = 1;
	while (compnum(y->re, sup) > 0) {
		if (y->sgr>0) t = minus(y, p);
		else t = plus(y, p);
		delvar(y);
		y = t;
	}
	while (compnum(y->im, sup) > 0) {
		if (y->sgi>0) t = minus(y, q);
		else t = plus(y, q);
		delvar(y);
		y = t;
	}
	ans = _coss(y, acu);
	delnum(sup); delvar(y); delvar(p); delvar(q);
	return ans;
}
var _tan(var x, int acu) {
	var s, t, ans;
	s = _sin(x, acu + 1);
	t = _cos(x, acu + 1);
	ans = adivd(s, t, acu + 1);
	delvar(s);
	delvar(t);
	return ans;
}
var _sinh(var x, int acu) {
	var s = v("-i"), t = v("i"), p, q, ans;
	p = mult(x, t);
	q = _sin(p, acu);
	ans = mult(s, q);
	delvar(s);
	delvar(t);
	delvar(p);
	delvar(q);
	return ans;
}
var _cosh(var x, int acu) {
	var t = v("i"), p, ans;
	p = mult(x, t);
	ans = _cos(p, acu);
	delvar(t);
	delvar(p);
	return ans;
}
var _tanh(var x, int acu) {
	var s = v("-i"), t = v("i"), p, q, ans;
	p = mult(x, t);
	q = _tan(p, acu);
	ans = mult(s, q);
	delvar(s);
	delvar(t);
	delvar(p);
	delvar(q);
	return ans;
}
static var arctans(var x, int acu) {
	var y, f = v("1"), p, ans, two = v("2");
	var s, t;
	p = copyvar(x);
	y = mult(x, p);
	ans = copyvar(x);
	while (1) {
		t = p;
		p = mult(p, y);
		delvar(t);
		t = f;
		f = plus(f, two);
		delvar(t);
		op(f);
		op(two);
		s = adivd(p, f, acu + 1);
		if (iszero(s) == 1) {
			delvar(s);
			break;
		}
		t = ans;
		ans = plus(ans, s);
		delvar(s);
		delvar(t);
	}
	delvar(f); delvar(p); delvar(two);
	ans = avar(ans, acu);
	return ans;
}
var arctan(var x, int acu) {
	var _pi, ans, y, temp, halfpi, quarterpi, one, two, four, p, q;
	number bd;
	if (x == NULL) return NULL;
	if (!isnumberzero(x->im)) {
		printerr(9);
		return NULL;
	}
	if (x->sgr < 0) {
		ans = op(arctan(op(x), acu));
		op(x);
		return ans;
	}
	bd = num("1");
	if (compnum(x->re, bd)>0) {
		y = rev(x, acu + 2);
		temp = arctan(y, acu + 1);
		_pi = pi(acu + 1);
		two = v("2");
		halfpi = adivd(_pi, two, acu + 1);
		ans = avar(minus(halfpi, temp), acu);
		delvar(y); delvar(temp); delvar(_pi); delvar(two); delvar(halfpi);
		delnum(bd);
		return ans;
	}
	delnum(bd);
	bd = num("0.7");
	if (compnum(x->re, bd) > 0) {
		_pi = pi(acu + 1);
		four = v("4");
		quarterpi = adivd(_pi, four, acu + 1);
		one = v("1");
		p = plus(one, x);
		q = minus(one, x);
		y = adivd(q, p, acu + 2);
		temp = arctan(y, acu + 1);
		ans = avar(minus(quarterpi, temp), acu);
		delvar(_pi); delvar(four); delvar(quarterpi); delvar(y); delvar(temp); delvar(one); delvar(p); delvar(q);
		delnum(bd);
		return ans;
	}
	delnum(bd);
	return arctans(x, acu);
}
var arcsin(var x, int acu) {
	var _pi, ans, t1, t2, t3, t4, t5, t6;
	number one;
	int k;
	if (x == NULL) return NULL;
	if (!isnumberzero(x->im)) {
		printerr(12);
		return NULL;
	}
	if (isnumberzero(x->re)) return newvar();
	one = num("1");
	k = compnum(x->re, one);
	delnum(one);
	if (k > 0) {
		printerr(12);
		return NULL;
	}
	if (x->sgr < 0) {
		ans = op(arcsin(op(x), acu));
		op(x);
		return ans;
	}
	if (k == 0) {
		_pi = pi(acu + 1);
		t1 = v("2");
		ans = adivd(_pi, t1, acu);
		delvar(_pi); delvar(t1);
		return ans;
	}
	t1 = avar(powerint(x, 2),acu+4);
	t2 = rev(t1, acu + 3);
	t3 = v("1");
	t4 = minus(t2, t3);
	t5 = rev(t4, acu + 2);
	t6 = _sqrt(t5, acu + 1);
	ans = arctan(t6, acu);
	delvar(t1); delvar(t2); delvar(t3); delvar(t4); delvar(t5); delvar(t6);
	return ans;
}
var arccos(var x, int acu) {
	var _pi, ans, t1, t2, t3;
	number one;
	int k;
	if (x == NULL) return NULL;
	if (!isnumberzero(x->im)) {
		printerr(13);
		return NULL;
	}
	one = num("1");
	k = compnum(x->re, one);
	delnum(one);
	if (k > 0) {
		printerr(13);
		return NULL;
	}
	if (k == 0 && x->sgr > 0) return newvar();
	if (k == 0) return pi(acu);
	_pi = pi(acu + 2);
	t1 = v("2");
	t2 = adivd(_pi, t1, acu + 1);
	t3 = arcsin(x, acu + 1);
	ans = avar(minus(t2, t3), acu);
	delvar(_pi);
	delvar(t1); delvar(t2); delvar(t3);
	return ans;
}
var rev(var x, int acu) {
	var one = v("1"), ans;
	ans = adivd(one, x, acu);
	delvar(one);
	return ans;
}
var e(int acu) {
	var one = v("1"), ans;
	ans = _exp(one, acu);
	delvar(one);
	return ans;
}
varlist insertvar(var x, char name[], varlist* pvl) {
	int k;
	varlist ivc, p;
	if (*pvl != NULL) {
		k = 1;
		p = *pvl;
		if (strcmp(p->name, name) == 0) k = 0;
		while (p->next != NULL) {
			p = p->next;
			if (strcmp(p->name, name) == 0) {
				k = 0;
				break;
			}
		}
		if (k == 0) {
			printerr(301);
			return NULL;
		}
	}
	ivc = (varlist)malloc(sizeof(varco));
	if (ivc == NULL) {
		printerr(300);
		system("pause");
		exit(0);
	}
	ivc->x = x;
	strcpy(ivc->name, NAME_LEN, name);
	ivc->ep = NULL;
	ivc->type = -1;
	if (*pvl == NULL) ivc->next = NULL;
	else ivc->next = *pvl;
	*pvl = ivc;
	return ivc;
}
varlist removevar(char name[], varlist vl) {
	varlist p, pre;
	if (vl == NULL) {
		printerr(302);
		return vl;
	}
	p = vl;
	if (strcmp(p->name, name) == 0) {
		delvar(p->x);
		delnum(p->ep);
		vl = p->next;
		free(p);
		return vl;
	}
	pre = vl;
	while (p->next != NULL) {
		p = p->next;
		if (strcmp(p->name, name) == 0) {
			delvar(p->x);
			delnum(p->ep);
			pre->next = p->next;
			free(p);
			return vl;
		}
		pre = p;
	}
	//printerr(303);
	return vl;
}
var varname(char name[], varlist vl) {
	varlist p;
	if (vl == NULL) return NULL;
	p = vl;
	if (strcmp(p->name, name) == 0) return p->x;
	while (p->next != NULL) {
		p = p->next;
		if (strcmp(p->name, name) == 0) return p->x;
	}
	return NULL;
}
expr exprname(char name[], varlist vl) {
	varlist p;
	if (vl == NULL) return NULL;
	p = vl;
	if (strcmp(p->name, name) == 0) return p->ep;
	while (p->next != NULL) {
		p = p->next;
		if (strcmp(p->name, name) == 0) return p->ep;
	}
	return NULL;
}
varlist pvarname(char name[], varlist vl) {
	varlist p;
	if (vl == NULL) return NULL;
	p = vl;
	if (strcmp(p->name, name) == 0) return p;
	while (p->next != NULL) {
		p = p->next;
		if (strcmp(p->name, name) == 0) return p;
	}
	return NULL;
}
varlist pvarnameep(expr ep, varlist vl) {
	varlist p;
	char* c;
	expr q;
	if (vl == NULL) return NULL;
	p = vl;
	do{
		c = p->name;
		q = ep;
		while (q != NULL && *c == q->d) {
			c++; q = q->next;
		}
		if (*c == 0 && q == NULL) return p;
	} while ((p = p->next) != NULL);
	return NULL;
}
varlist newvarlist() {
	varlist vl = NULL;
	insertvar(newvar(), "ans", &vl);
	insertvar(v("20"), "acu", &vl);
	insertvar(v("2.7182818284590452353"), "E", &vl);
	insertvar(v("3.1415926535897932384"), "Pi", &vl);
//	insertvar(v("0.5772156649015328606"), "Euler_gamma", &vl);
	insertvar(v("i"), "i", &vl);
	return vl;
}
void delvarlist(varlist vl) {
	varlist next;
	if (vl == NULL) return;
	while (vl->next != NULL) {
		next = vl->next;
		delvar(vl->x);
		delnum(vl->ep);
		free(vl);
		vl = next;
	}
	delvar(vl->x);
	free(vl);
}
var realpart(var x) {
	var ans;
	if (x == NULL) return NULL;
	ans = newvar();
	ans->sgr = x->sgr;
	ans->re = copynum(x->re);
	return ans;
}
var imagpart(var x) {
	var ans;
	if (x == NULL) return NULL;
	ans = newvar();
	ans->sgr = x->sgi;
	ans->re = copynum(x->im);
	return ans;
}
var conjc(var x) {
	var ans;
	if (x == NULL) return NULL;
	ans = copyvar(x);
	ans->sgi = -ans->sgi;
	return ans;
}
var vexp(expr ep) {
	int i;
	char sg;
	digt *p = ep, *temp;
	expr c[2];
	var x = newvar();
	for (i = 0; i < 2; i++) {
		sg = 1;
		if (p->d == '+' || p->d == '-') {
			if (p->d == '-') sg = -1;
			p = p->next;
		}
		temp = p;
		if (isnumber(p)) {
			while (isnumber(p->next)) p = p->next;
			c[i] = copyexpr(temp, p);
			p = p->next;
		}
		else c[i] = ex("1");
		if (p != NULL&&p->d == 'i') {
			x->sgi = sg;
			x->im = numexp(c[i]);
			p = p->next;
		}
		else {
			x->sgr = sg;
			x->re = numexp(c[i]);
		}
		if (p == NULL) return x;
	}
	return x;
}
number numexp(expr ep) {
	number n;
	digt *p, *q;
	if (ep == NULL) return NULL;
	n = newnum();
	p = n;
	q = bottomnum(ep);
	p->d = q->d-'0';
	while (q->next != NULL) {
		q = q->next;
		p = calldigt(p, q->d-'0', 'p');
	}
	n = bottomnum(n);
	p = n;
	while (p != NULL&&p->d != '.' - '0') p = p->next;
	if (p == NULL) return n;
	n = next(p);
	deldigt(p, 0);
	return n;
}
void insertexpr(expr ep, char name[], varlist* pvl) {
	int k;
	varlist ivc, p;
	if (*pvl != NULL) {
		k = 1;
		p = *pvl;
		if (strcmp(p->name, name) == 0) k = 0;
		while (p->next != NULL) {
			p = p->next;
			if (strcmp(p->name, name) == 0) {
				k = 0;
				break;
			}
		}
		if (k == 0) {
			printerr(301);
			return;
		}
	}
	ivc = (varlist)malloc(sizeof(varco));
	if (ivc == NULL) {
		printerr(300);
		system("pause");
		exit(0);
	}
	ivc->x = NULL;
	strcpy(ivc->name, NAME_LEN, name);
	ivc->ep = ep;
	ivc->type = 0;
	if (*pvl == NULL) ivc->next = NULL;
	else ivc->next = *pvl;
	*pvl = ivc;
}
static var ceilr(var x) {
	int k = 0;
	number p, t, one;
	var ans;
	ans = newvar();
	ans->sgr = x->sgr;
	ans->re = copynum(x->re);
	p = ans->re;
	while (p->pre != NULL) {
		p = p->pre;
		if (p->d != 0) {
			k = 1;
			break;
		}
	}
	p = bottomnum(ans->re);
	while (p != ans->re) p = deldigt(p, 'n');
	if (k == 1) {
		one = num("1");
		t = ans->re;
		ans->re = plusnum(ans->re, one);
		delnum(t);
		delnum(one);
	}
	return ans;
}
static var floorr(var x) {
	{
		number p;
		var ans;
		ans = newvar();
		ans->sgr = x->sgr;
		ans->re = copynum(x->re);
		p = bottomnum(ans->re);
		while (p != ans->re) p = deldigt(p, 'n');
		return ans;
	}
}
var _floor(var x) {
	if (x == NULL) return NULL;
	if (x->sgr == 1) return floorr(x);
	else return ceilr(x);
}
var _ceil(var x) {
	if (x->sgr == 1) return ceilr(x);
	else return floorr(x);
}
var _abs(var x, int acu) {
	var ans;
	number t;
	var re, im, sre, sim;
	if (x == NULL) return NULL;
	if (isnumberzero(x->im)) {
		ans = copyvar(x);
		ans->sgr = 1;
		return ans;
	}
	if (isnumberzero(x->re)) {
		ans = copyvar(x);
		ans->sgr = 1;
		t = ans->re;
		ans->re = ans->im;
		ans->im = t;
		return ans;
	}
	re = realpart(x);
	im = imagpart(x);
	sre = powerint(re, 2);
	sim = powerint(im, 2);
	delvar(re);
	delvar(im);
	re = plus(sre, sim);
	delvar(sre);
	delvar(sim);
	ans = _sqrt(re, acu);
	delvar(re);
	return ans;
}
static int _randint(int inf, int sup) {
	static int seed = 0;
	srand(seed);
	seed = (unsigned)(time(NULL)*(seed+1));
	return rand() % (sup - inf + 1) + inf;
}
static  number _rands(number inf, number sup) {
	digt *p, *q, *t;
	int in, su, m, n;
	p = inf; q = sup;
	while (p->next != NULL || q->next != NULL) {
		p = next(p);
		q = next(q);
	}
	m = n = 1;
	t = newnum();
	in = p->d; su = q->d;
	t->d = _randint(in, su);
	if (t->d != in) m = 0;
	if (t->d != su) n = 0;
	while (p != inf) {
		p = pre(p);
		q = pre(q);
		t = pre(t);
		if (m == 0) in = 0;
		else in = p->d;
		if (n == 0) su = 9;
		else su = q->d;
		t->d = _randint(in, su);
		if (t->d != in) m = 0;
		if (t->d != su) n = 0;
	}
	refreshnum(inf);
	refreshnum(sup);
	refreshnum(t);
	return t;
}
number _rand(number inf, number sup) {
	digt *p, *q, *t;
	number ranup, addran, zero, ans, tinf, tsup;
	p = inf; q = sup;
	ranup = newnum();
	t = ranup;
	t->d = 9;
	while (p->next != NULL || q->next != NULL) {
		p = next(p);
		q = next(q);
		t = calldigt(t, 9, 'n');
	}
	zero = newnum();
	addran = _rands(zero, ranup);
	delnum(zero);delnum(ranup);
	tinf = plusnum(inf, addran);
	tsup = plusnum(sup, addran);
	ranup = _rands(tinf, tsup);
	delnum(tinf); delnum(tsup);
	ans = minusnum(ranup, addran);
	delnum(ranup); delnum(addran);
	return ans;
}
expr newexpr() {
	return newnum();
}
void strtoexpr(char* str, expr *pn) {
	digt* p;
	delnum(*pn);
	if (*str == 0) {
		*pn = NULL;
		return;
	}
	*pn = newnum();
	p = *pn;
	p->d = *str;
	str++;
	while (*str) {
		p = calldigt(p, *str, 'n');
		str++;
	}
}
void printexpr(expr n) {
	digt* p = n;
	if (p == NULL) return;
	p = bottomnum(p);
	putchar(p->d);
	while (p->next != NULL) {
		p = p->next;
		putchar(p->d);
	}
}
void exprtostr(expr n, char *str) {
	digt* p = n;
	if (p == NULL) return;
	p = bottomnum(p);
	*str = p->d; str++;
	while (p->next != NULL) {
		p = p->next;
		*str = p->d; str++;
	}
	*str = 0;
}
void getexpr(expr *pn) {
	char str[MAX_STR];
	gets(str, MAX_STR);
	strtoexpr(str, pn);
}
expr ex(char* str) {
	expr n = newnum();
	strtoexpr(str, &n);
	return n;
}
expn exn(char*str) {
	expn en = newexpn();
	defineexpn(en, ex(str));
	return en;
}
digt* insertdigt(digt* p, char d, char mode) {
	digt* dig;
	if (p == NULL) return NULL;
	if ((mode != 'n'&&mode != 'p')) return NULL;
	dig = (digt*)malloc(sizeof(digt));
	if (dig == NULL) {
		printerr(100);
		system("pause");
		exit(0);
	}
	dig->d = d;
	if (mode == 'n') {
		dig->pre = p;
		dig->next = p->next;
		if (p->next != NULL) p->next->pre = dig;
		p->next = dig;
	}
	if (mode == 'p') {
		dig->pre = p->pre;
		dig->next = p;
		if (p->pre != NULL) p->pre->next = dig;
		p->pre = dig;
	}
	return dig;
}
static digt* opps(digt* p, char a, char b) {
	int c = 1;
	if (p->d == a) {
		while (p->next != NULL&&c != 0) {
			p = p->next;
			if (a != '[' && p->d == '[') {
				p = opps(p, '[', ']');
				if (p == NULL) return NULL;
			}
			if (p->d == '\"') {
				p = nextqu(p);
				if (p == NULL) return NULL;
			}
			if (p->d == a) c++;
			if (p->d == b) c--;
		}
		if (c == 0) return p;
		else {
#ifdef COLOR_ERRIO
			printf(COLOR_ERROR"Syntax Error:Missing '%c'.\n"COLOR_OUTPUT, b);
#else
			printf("Syntax Error:Missing '%c'.\n", b);
#endif
			return NULL;
		}
	}
	if (p->d == b) {
		while (p->pre != NULL&&c != 0) {
			p = p->pre;
			if (b != ']' && p->d == ']') {
				p = opps(p, '[', ']');
				if (p == NULL) return NULL;
			}
			if (p->d == '\"') {
				p = prequ(p);
				if (p == NULL) return NULL;
			}
			if (p->d == b) c++;
			if (p->d == a) c--;
		}
		if (c == 0) return p;
		else {
#ifdef COLOR_ERRIO
			printf(COLOR_ERROR"Syntax Error:Missing '%c'.\n"COLOR_OUTPUT, b);
#else
			printf("Syntax Error:Missing '%c'.\n", b);
#endif
			return NULL;
		}
	}
	return NULL;
}
digt* opp(digt* p) {
	if (p == NULL) return NULL;
	if (p->d == '(' || p->d == ')') return opps(p, '(', ')');
	if (p->d == '[' || p->d == ']') return opps(p, '[', ']');
	if (p->d == '{' || p->d == '}') return opps(p, '{', '}');
	return NULL;
}
digt* nextchar(digt* p, char d) {
	if (p->d == '[') p = opp(p);
	if (p->d == '\"') p = nextqu(p);
	while (p->next != NULL) {
		p = p->next;
		if (p->d == '[') p = opp(p);
		if (p->d == '\"') p = nextqu(p);
		if (p->d == d) return p;
	}
	return NULL;
}
digt* nextcharor(digt* p, char c, char d) {
	if (p->d == '[') p = opp(p);
	if (p->d == '\"') p = nextqu(p);
	while (p->next != NULL) {
		p = p->next;
		if (p->d == '[') p = opp(p);
		if (p->d == '\"') p = nextqu(p);
		if (p->d == d || p->d == c) return p;
	}
	return NULL;
}
digt* prechar(digt* p, char d) {
	if (p->d == ']') p = opp(p);
	if (p->d == '\"') p = prequ(p);
	while (p->pre != NULL) {
		p = p->pre;
		if (p->d == ']') p = opp(p);
		if (p->d == '\"') p = prequ(p);
		if (p->d == d) return p;
	}
	return NULL;
}
digt* precharor(digt* p, char c, char d) {
	if (p->d == ']') p = opp(p);
	if (p->d == '\"') p = prequ(p);
	while (p->pre != NULL) {
		p = p->pre;
		if (p->d == ']') p = opp(p);
		if (p->d == '\"') p = prequ(p);
		if (p->d == d || p->d == c) return p;
	}
	return NULL;
}
digt* jumpnextchar(digt* p, char d) {
	int m, n;
	m = n = 0;
	while (p->next != NULL) {
		p = p->next;
		if (p->d == '(') m++;
		if (p->d == ')') m--;
//		if (p->d == '{') n++;
//		if (p->d == '}') n--;
		if (p->d == '[') p = opp(p);
		if (p->d == '\"') p = nextqu(p);
		if (m == 0 && n == 0 && p->d == d) return p;
	}
	return NULL;
}
int isnumber(digt* p) {
	if (p == NULL) return 0;
	if ((p->d <= '9'&&p->d >= '0') || p->d == '.') return 1;
	else return 0;
}
int isalpha(digt* p) {
	if (p == NULL) return 0;
	if ((p->d <= 'z'&&p->d >= 'a') || (p->d <= 'Z'&&p->d >= 'A') || p->d == '_') return 1;
	else return 0;
}
int isalphanumber(digt* p) {
	if (isalpha(p) || isnumber(p)) return 1;
	else return 0;
}
digt* jumpnumber(digt* p, char mode) {
	if (mode != 'n'&&mode != 'p') return NULL;
	if (mode == 'n') {
		while (isnumber(p)) p = p->next;
		return p;
	}
	else {
		while (isnumber(p)) p = p->pre;
		return p;
	}
}
digt* jumpunit(digt* p, char mode) {
	int k;
	k = 0;
	if (p == NULL) return NULL;
	if (mode != 'n'&&mode != 'p') return NULL;
	if (mode == 'n') {
		while (p != NULL) {
			if (p->d == '(') k++;
			if (p->d == ')') k--;
			if (k < 0) return p;
			if (p->d == '[') p = opp(p);
			if (p->d == '\"') p = nextqu(p);
//			if (k == 0 && isoperator(p) && isdouble(p)) return p;
			if (k == 0 && isoperator(p)) return p;
			p = p->next;
		}
		return p;
	}
	else {
		while (p != NULL) {
			if (p->d == ')') k++;
			if (p->d == '(') k--;
			if (k < 0) return p;
			if (p->d == ']') p = opp(p);
			if (p->d == '\"') p = prequ(p);
//			if (k == 0 && isoperator(p) && isdouble(p)) return p;
			if (k == 0 && isoperator(p)) return p;
			p = p->pre;
		}
		return p;
	}
}
int issingle(digt* p) {
	if (p == NULL || p->next == NULL || p->next->d == ')' || p->next->d == ']') return 0;
	if (p->pre == NULL) return 1;
	if (p->pre->d == '(' || p->pre->d == '[' || isoperator(p->pre)) return 1;
	return 0;
}
int isdouble(digt* p) {
	if (p == NULL || p->next == NULL || p->pre == NULL) return 0;
	if (p->pre->d == '(' || p->pre->d == '[' || isoperator(p->pre)) return 0;
	if (p->next->d == ')' || p->next->d == ']' || (isoperator(p->next)&&!issingle(p->next))) return 0;
	return 1;
}
void addforsingle(digt* p) {
	digt* q = p;
	insertdigt(q, '(', 'p');
	q = insertdigt(q, '(', 'n');
	q = q->next;
	q = jumpunit(q, 'n');
	if (q != NULL) {
		q = insertdigt(q, ')', 'p');
		q = insertdigt(q, ')', 'p');
	}
	else {
		q = topnum(p);
		q = insertdigt(q, ')', 'n');
		q = insertdigt(q, ')', 'n');
	}
}
void addfordouble(digt* p) {
	digt* q = p;
	q = insertdigt(q, ')', 'p');
	q = q->pre;
	q = jumpunit(q, 'p');
	if (q != NULL) {
		q = insertdigt(q, '(', 'n');
		q = insertdigt(q, '(', 'n');
	}
	else {
		q = bottomnum(p);
		q = insertdigt(q, '(', 'p');
		q = insertdigt(q, '(', 'p');
	}
	q = p;
	q = insertdigt(q, '(', 'n');
	q = q->next;
	q = jumpunit(q, 'n');
	if (q != NULL) {
		q = insertdigt(q, ')', 'p');
		q = insertdigt(q, ')', 'p');
	}
	else {
		q = topnum(p);
		q = insertdigt(q, ')', 'n');
		q = insertdigt(q, ')', 'n');
	}
}
void antiaddsingleor(expr ep, char a, char b) {
	expr p = topnum(ep);
	if ((p->d == a || p->d == b)&&issingle(p)) addforsingle(p);
	p = precharor(p, a, b);
	while (p != NULL) {
		if (issingle(p)) addforsingle(p);
		p = precharor(p, a, b);
	}
}
void antiaddsingle(expr ep, char a) {
	expr p = topnum(ep);
	if (p->d == a&&issingle(p)) addforsingle(p);
	p = prechar(p, a);
	while (p != NULL) {
		if (issingle(p)) addforsingle(p);
		p = prechar(p, a);
	}
}
void adddouble(expr ep, char a) {
	expr p = bottomnum(ep);
	if (p->d == a&&isdouble(p)) addfordouble(p);
	p = nextchar(p, a);
	while (p != NULL) {
		if(isdouble(p)) addfordouble(p);
		p = nextchar(p, a);
	}
}
void antiadddouble(expr ep, char a) {
	expr p = topnum(ep);
	if (p->d == a&&isdouble(p)) addfordouble(p);
	p = prechar(p, a);
	while (p != NULL) {
		if (isdouble(p)) addfordouble(p);
		p = prechar(p, a);
	}
}
void adddoubleor(expr ep, char a, char b) {
	expr p = bottomnum(ep);
	if ((p->d == a || p->d == b)&& isdouble(p)) addfordouble(p);
	p = nextcharor(p, a, b);
	while (p != NULL) {
		if (isdouble(p)) addfordouble(p);
		p = nextcharor(p, a, b);
	}
}
void initialexpr(expr ep) {
	antiaddsingle(ep, ':');
	antiaddsingle(ep, '!');
	antiadddouble(ep, '^');
	antiaddsingleor(ep, '+', '-');
	adddoubleor(ep, '*', '/');
	adddouble(ep, '%');
	adddoubleor(ep, '+', '-');
	adddoubleor(ep, '>', '<');
	adddouble(ep, '?');
	adddouble(ep, '&');
	adddouble(ep, '|');
	antiadddouble(ep, '=');
	antiaddsingle(ep, '@');
	adddouble(ep, '@');
	antiadddouble(ep, ',');
	antiadddouble(ep, ' ');
}
expn newexpn() {
	expn e = (expn)malloc(sizeof(struct explist));
	if (e == NULL) {
		printerr(400);
		system("pause");
		exit(0);
	}
	e->type = 0;
	e->prop = 0;
	e->ep = NULL;
	e->next[0] = NULL;
	e->next[1] = NULL;
	e->pre = NULL;
	e->pre_s = NULL;
	e->pre_e = NULL;
	e->retu = NULL;
	e->it = NULL;
	e->ip = NULL;
	e->name[0] = 0;
	e->func[0] = 0;
	return e;
}
void defineexpn(expn en, expr ep) {
	if (ep == NULL) {
		printerr(401);
		return;
	}
	if (en->type != 0) {
		printerr(402);
		return;
	}
	/*if (!charcheckforexpr(ep)) {
		printerr(403);
		return;
	}*/
	en->ep = ep;
	en->type = 1;
}
void initialize(expn en) {
	expr p;
	if (en->type != 1) {
		printerr(404);
		return;
	}
	if (!oppcheckoutba(en->ep)) return;
	p = en->ep;
	while (p != NULL) {
		if (p->d == '[') p = opp(p);
		if (p->d == '\"') p = nextqu(p);
		if (isoperator(p)&&!isoperative(p)) {
//			printerr(419);
			return;
		}
		p = p->next;
	}
	initialexpr(en->ep);
	en->ep = bottomnum(en->ep);
	en->type = 2;
}
digt* deldigt(digt* p, char mode) {
	digt* q = NULL;
	if (p == NULL) return q;
	if (mode == 'p') q = p->pre;
	if (mode == 'n') q = p->next;
	if (p->next != NULL) p->next->pre = p->pre;
	if (p->pre != NULL) p->pre->next = p->next;
	free(p);
	return q;
}
expr removeoutadd(expr ep) {
	digt* p = bottomnum(ep);
	digt* q = topnum(ep);
	while (p->d == '(' && opp(p) == q) {
		p = deldigt(p, 'n');
		q = deldigt(q, 'p');
		if (q == NULL) return NULL;
	}
	return p;
}
int removeoutba(expr* ep) {
	digt* p = bottomnum(*ep);
	digt* q = topnum(*ep);
	int s = 1;
	while (p->d == '[' && opp(p) == q) {
		p = deldigt(p, 'n');
		q = deldigt(q, 'p');
		if (q == NULL) return 0;
		s = 2;
	}
	*ep = p;
	return s;
}
expr removeoutqu(expr ep) {
	digt* p, * q;
	if (ep == NULL) return NULL;
	p = bottomnum(ep);
	q = topnum(ep);
	if (p->d == '\"' && q->d == '\"') {
		if (p->next == q) {
			delnum(ep);
			return NULL;
		}
		else {
			p = deldigt(p, 'n');
			q = deldigt(q, 'p');
			return p;
		}
	}
	return ep;
}
expr copyexpr(digt* start, digt* end) {
	expr ans;
	digt *p, *q;
	ans = newnum();
	p = ans; q = start;
	p->d = q->d;
	while (q != end) {
		q = q->next;
		p = calldigt(p, q->d, 'n');
	}
	return ans;
}
void logicalize(expn en, varlist* pvl) {
	digt *q, *r, *t;
	expr ep, temp;
	varlist ans, tempvl;
	int s, i;
	char str[NAME_LEN];
	if (en->type == 1) {
		initialize(en);
		if (en->type == 1) return;
	}
	en->ep = removeoutadd(en->ep);
	if (en->ep == NULL) {
		printerr(-401);
		en->ep = ex("0");
	}
	s = removeoutba(&(en->ep));
	if (s == 0) en->ep = ex("ans");
	if (s == 2) {
		if (en->pre != NULL && en->pre->func[0] == ' ') {
			en->ep = addoutba(en->ep, '[', ']');
			en->type = 3;
			en->prop = 1;
			return;
		}
		en->type = 5;
//		en->prop = 4;
		if (en->pre == NULL || (en->pre->func[0] != '=' && en->pre->func[0] != '@'&& en->pre->func[0] != '\\')) {
			if (en->ep->d == '>' && en->ep->next != NULL) {
				en->ep = deldigt(en->ep, 'n');
				tempvl = newvarlist();
				calcstc(en->ep, &tempvl);
				ans = pvarname("ans", tempvl);
				if (ans != NULL) {
					en->ep = copynum(ans->ep);
					en->retu = copyvar(ans->x);
					if (ans->type == -1) en->type = 4;
				}
				delvarlist(tempvl);
			}
			else {
				calcstc(en->ep, pvl);
				ans = pvarname("ans", *pvl);
				if (ans != NULL) {
					en->ep = copynum(ans->ep);
					en->retu = copyvar(ans->x);
					if (ans->type == -1) en->type = 4;
				}
			}
		}
		if (en->pre != NULL && en->pre->func[0] == '=') {
			en->ep = addoutba(en->ep, '[', ']');
			en->prop = 1;
		}
		return;
	}
	ep = en->ep;
	if (ep->d != '(' && !isoperator(ep)) {
		q = nextchar(ep, '(');
		if (q == NULL) {
			if (isnumber(ep)) {
				if (!istheexprnumber(ep)) {
					//printerr(408);
					r = jumpnumber(ep, 'n');
					insertdigt(ep, '(', 'p');
					insertdigt(r, ')', 'p');
					insertdigt(r, '*', 'p');
					insertdigt(r, '(', 'p');
					insertdigt(topnum(ep), ')', 'n');
					ep = ep->pre;
					en->ep = ep;
					logicalize(en, pvl);
					return;
				}
				en->retu = vexp(ep);
				en->type = 4;
				en->prop = 1;
				return;
			}
			if (lennum(ep) >= NAME_LEN) {
				//printerr(409);
				en->type = 5;
				en->prop = 2;
				return;
			}
			if (!istheexprname(ep)) {
				//printerr(410);
				en->type = 3;
				en->prop = 2;
				return;
			}
			exprtostr(ep, str);
			strcpy(en->func, NAME_LEN, str);
			if (en->name[0] == 0) strcpy(en->name, NAME_LEN, str);
			/*if (en->pre != NULL && ((en->pre->func[0] == '=' || en->pre->func[0] == ':') && en->pre->next[0] == en) || strcmp(en->func, "tovar") != 0) {
				en->type = 5;
				en->prop = 1;
				return;
			}*/
			/*p = pvarname(str, *pvl);
			if (p == NULL) {
				en->type = 5;
				en->prop = 1;
				return;
			}
			if (p->type == -1) {
				en->retu = copyvar(p->x);
				en->type = 4;
				en->prop = 1;
				return;
			}
			if (p->type == 0) {
				resetexpn(en);
				en->ep = copynum(p->ep);
				en->type = 1;
				iteration_number++;
				if (iteration_number > ITERATION_MAX) return;
				logicalize(en, pvl);
			}
			if (p->type > 0) {
				printerr(421);
				return;
			}*/
			en->type = 3;
			en->prop = 1;
			return;
		}
		else {
			if (isnumber(ep)) {
				//printerr(411);
				r = jumpnumber(ep, 'n');
				insertdigt(ep, '(', 'p');
				insertdigt(r, ')', 'p');
				insertdigt(r, '*', 'p');
				insertdigt(r, '(', 'p');
				insertdigt(topnum(ep), ')', 'n');
				ep = ep->pre;
				en->ep = ep;
				logicalize(en, pvl);
				return;
			}
			t = opp(q);
			if (t->next!=NULL) {
				insertdigt(ep, '(', 'p');
				insertdigt(t, '(', 'n');
				insertdigt(t, '*', 'n');
				insertdigt(t, ')', 'n');
				insertdigt(topnum(ep), ')', 'n');
				ep = ep->pre;
				en->ep = ep;
				logicalize(en, pvl);
				return;
			}
			temp = copyexpr(ep, q->pre);
			s = removeoutba(&temp);
			if (s == 0) {
				tempvl = *pvl;
				while (tempvl != NULL) {
					if (tempvl->type > 0) {
						temp = ex(tempvl->name);
						break;
					}
					tempvl = tempvl->next;
				}
				if (tempvl == NULL) {
					en->type = 3;
					en->prop = 1;
					return;
				}
			}
			if (s == 2) {
				calcstc(temp, pvl);
				delnum(temp);
				ans = pvarname("ans", *pvl);
				if (ans == NULL || ans->type > 0) {
					printerr(413);
					return;
				}
				if (ans->type == 0) temp = removeoutqu(copynum(ans->ep));
				else {
					if (q->next == t) {
						printerr(401);
						return;
					}
					if (!ispositiveinteger(ans->x) && !iszero(ans->x)) {
						printerr(426);
						return;
					}
					s = vartoint(ans->x);
					if (s == 0) {
						en->retu = newvar();
						en->type = 4;
						en->prop = 1;
						return;
					}
					temp = copyexpr(q->next, t->pre);
					for (i = 0; i < s; i++) calcstc(temp, pvl);
					delnum(temp);
					ans = pvarname("ans", *pvl);
					en->type = 5;
					if (ans != NULL) {
						en->ep = copynum(ans->ep);
						en->retu = copyvar(ans->x);
						if (ans->type == -1) en->type = 4;
					}
					return;
				}
			}
			if (lennum(temp) >= NAME_LEN) {
				printerr(412);
				delnum(temp);
				return;
			}
			if (!istheexprname(temp)) {
				printerr(413);
				delnum(temp);
				return;
			}
			exprtostr(temp, en->func);
			if (en->name[0] == 0) exprtostr(temp, en->name);
			delnum(temp);
			while (q->next->d == '('&&t->pre->d == ')'&&opp(q->next) == t->pre) {
				deldigt(q->next, 0);
				deldigt(t->pre, 0);
			}
			if (q->next != t) {
				en->next[0] = definebycopy(en, q->next, t->pre);
				en->type = 3;
				en->prop = 1;
				return;
			}
			/*if (en->pre != NULL && ((en->pre->func[0] == '=' || en->pre->func[0] == ':') && en->pre->next[0] == en) || strcmp(en->func, "tovar") != 0) {
				en->type = 5;
				en->prop = 1;
				return;
			}*/
			/*if ((p = pvarname(en->func, *pvl)) != NULL&&(p->type >= 0)) {
				if (p->type > lenarray(en->next[0])) {
					printerr(421);
					return;
				}
				f = copynum(p->ep);
				if (en->next[0] != NULL) {
					px = ex("\1");
					a = removeoutadd(copynum(en->next[0]->ep));
					f = replace(f, px, a);
					delnum(a);
					delnum(px);
				}
				if (en->next[1] != NULL) {
					py = ex("\2");
					a = removeoutadd(copynum(en->next[1]->ep));
					f = replace(f, py, a);
					delnum(a);
					delnum(py);
				}
				resetexpn(en);
				en->ep = f;
				en->type = 2;
				iteration_number++;
				if (iteration_number > ITERATION_MAX) return;
				logicalize(en, pvl);
				return;
			}
			if (p != NULL && p->type == 4) {
				resetexpn(en);
				en->retu = copyvar(p->x);
				en->type = 4;
				en->prop = 1;
				return;
			}*/
			en->type = 3;
			en->prop = 1;
		}
	}
	else {
		if (isoperator(ep)) {
			en->func[0] = ep->d;
			en->func[1] = 0;
			q = ep->next;
			r = topnum(ep);
//			en->next[0] = newexpn();
//			defineexpn(en->next[0], ex("0"));
//			en->ep = insertdigt(en->ep, '0', 'p');
//			en->next[0]->pre = en;
//			en->next[0]->pre_s = en->ep;
//			en->next[0]->pre_e = en->ep;
//			en->next[0]->type = 2;
			en->next[0] = definebycopy(en, q, r);
			en->type = 3;
			en->prop = 3;
		}
		else {
			q = jumpunit(ep, 'n');
			if (q == NULL) {
				//printerr(414);
				r = opp(ep);
				q = insertdigt(r, '*', 'n');
			}
			en->func[0] = q->d;
			en->func[1] = 0;
			q = q->pre;
			r = topnum(ep);
			en->next[0] = definebycopy(en, ep, q);
			en->next[1] = definebycopy(en, q->next->next, r);
			en->type = 3;
			en->prop = 4;
		}
	}
}
void alllogicalize(expn en, varlist* pvl) {
//	if (iteration_number > ITERATION_MAX) return;
	if (en->type == 0 || en->type == 4 || en->type == 5) return;
	if (en->type == 1) initialize(en);
	if (en->type == 1) return;
	if (en->type == 2) logicalize(en, pvl);
	if (en->next[0] != NULL) alllogicalize(en->next[0], pvl);
	if (en->next[1] != NULL) alllogicalize(en->next[1], pvl);
}
void calcprint(expn en, varlist vl) {
	int p;
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	if (en->next[1] == NULL) {
		if (en->next[0]->type < 3) return;
		if (en->next[0]->type == 4) printvar(en->next[0]->retu);
		else printexpr(en->next[0]->ep);
		putchar('\n');
		en->retu = copyvar(en->next[0]->retu);
		delnum(en->ep); en->ep = copynum(en->next[0]->ep);
		if (en->retu != NULL) en->type = 4;
		else en->type = 5;
	}
	else {
		if (!istype(en->next[0], 4) || en->next[0]->type < 3) return;
		p = vartoint(en->next[0]->retu);
		if (p < 0 || p>3) return;
		if (en->next[1]->type == 4) {
			if (p == 1 || p == 3) printvarasfloat(en->next[1]->retu);
			else printvar(en->next[1]->retu);
		}
		else printexpr(en->next[1]->ep);
		if (p == 0 || p == 1) putchar('\n');
		en->retu = copyvar(en->next[1]->retu);
		delnum(en->ep); en->ep = copynum(en->next[0]->ep);
		if (en->retu != NULL) en->type = 4;
		else en->type = 5;
	}
}
void fcalcd(var f(var,var),expn en, varlist vl) {
	var zero;
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	if (en->next[1] == NULL) {
		if (!istype(en->next[0], 4) || (en->func[0] != '+' && en->func[0] != '-') || en->prop != 3) return;
		zero = v("0");
		en->retu = f(zero, en->next[0]->retu);
		delvar(zero);
		if (en->retu != NULL) en->type = 4;
	}
	else{
		if (!istype(en->next[0], 4) || !istype(en->next[1], 4)) return;
		en->retu = f(en->next[0]->retu, en->next[1]->retu);
		if (en->retu != NULL) en->type = 4;
	}
}
void calcremain(expn en, varlist vl) {
	number r;
	if (en->next[0] == NULL || en->next[1] == NULL) {
		printerr(415);
		return;
	}
	if (!istype(en->next[0], 4) || !istype(en->next[1], 4)) return;
	r = remain(en->next[0]->retu->re, en->next[1]->retu->re);
	if (r == NULL) return;
	en->retu = newvar();
	en->retu->re = r;
	en->type = 4;
}
void calcand(expn en, varlist vl) {
	var ans, a, b;
	number zero;
	if (en->next[0] == NULL || en->next[1] == NULL) {
		printerr(415);
		return;
	}
	if (!istype(en->next[0], 4) || !istype(en->next[1], 4)) return;
	zero = newnum();
	a = en->next[0]->retu;
	b = en->next[1]->retu;
	if (!compnum(a->re, zero) == 0 && !compnum(b->re, zero) == 0) ans = v("1");
	else ans = newvar();
	delnum(zero);
	en->retu = ans;
	if (en->retu != NULL) en->type = 4;
}
void calcor(expn en, varlist vl) {
	var ans, a, b;
	number zero;
	if (en->next[0] == NULL || en->next[1] == NULL) {
		printerr(415);
		return;
	}
	if (!istype(en->next[0], 4) || !istype(en->next[1], 4)) return;
	zero = newnum();
	a = en->next[0]->retu;
	b = en->next[1]->retu;
	if (!compnum(a->re, zero) == 0 || !compnum(b->re, zero) == 0) ans = v("1");
	else ans = newvar();
	delnum(zero);
	en->retu = ans;
	if (en->retu != NULL) en->type = 4;
}
void calcnot(expn en, varlist vl) {
	var ans;
	number zero;
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	if (!istype(en->next[0], 4)) return;
	zero = newnum();
	if (compnum(en->next[0]->retu->re, zero) == 0) ans = v("1");
	else ans = newvar();
	delnum(zero);
	en->retu = ans;
	if (en->retu != NULL) en->type = 4;
}
void calcbi(expn en, varlist vl) {
	var ans;
	if (en->next[0] == NULL || en->next[1] == NULL) {
		printerr(415); 
		return;
	}
	if (!istype(en->next[0], 4) || !istype(en->next[1], 4)) return;
	if (compreal(en->next[0]->retu, en->next[1]->retu) > 0) ans = v("1");
	else ans = newvar();
	en->retu = ans;
	if (en->retu != NULL) en->type = 4;
}
void calcsm(expn en, varlist vl) {
	var ans;
	if (en->next[0] == NULL || en->next[1] == NULL) {
		printerr(415); 
		return;
	}
	if (!istype(en->next[0], 4) || !istype(en->next[1], 4)) return;
	if (compreal(en->next[0]->retu, en->next[1]->retu) < 0) ans = v("1");
	else ans = newvar();
	en->retu = ans;
	if (en->retu != NULL) en->type = 4;
}
void calcqu(expn en, varlist vl) {
	var ans, c;
	if (en->next[0] == NULL || en->next[1] == NULL) {
		printerr(415); 
		return;
	}
	if (istype(en->next[0], 4) && istype(en->next[1], 4)) {
		c = minus(en->next[0]->retu, en->next[1]->retu);
		if (iszero(c)) ans = v("1");
		else ans = newvar();
		delvar(c);
	}
	else {
		if (compexpr(en->next[0]->ep, en->next[1]->ep)) ans = v("1");
		else ans = newvar();
	}
	en->retu = ans;
	if (en->retu != NULL) en->type = 4;
}
int vartoint(var x) {
	int ans;
	number p = x->re, n = x->re->pre;
	p = topnum(p);
	ans = p->d;
	while (p->pre != n) {
		p = p->pre;
		ans = 10 * ans + p->d;
	}
	return ans;
}
void calcpower(expn en, varlist* pvl) {
	int acu, k;
	var vacu;
	expr temp, num, exp;
	expn c, pow, pco;
	item n, r;
	if (en->next[0] == NULL || en->next[1] == NULL) {
		printerr(415); 
		return;
	}
	if (en->next[0]->type != 4) {
		temp = ex(VAR_E);
		if (compexpr_sans(en->next[0]->ep, temp) && !strcmp(en->next[1]->func, "ln") && en->next[1]->next[0] != NULL) {
			replaceexpn(en, en->next[1]->next[0]);
			delnum(temp);
			return;
		}
		delnum(temp);
	}
	if (en->next[0]->func[0] == '^' && en->next[0]->type != 4 && en->next[0]->next[0] != NULL && en->next[0]->next[1] != NULL && !(en->next[1]->type == 4 && isone(en->next[1]->retu))) {
		c = caspro(en->next[0]->next[1], en->next[1], pvl);
		pow = enep(connect(ex("("), connect(copynum(en->next[0]->next[0]->ep), connect(ex(")^("), connect(c->ep, ex(")"))))), pvl);
		c->ep = NULL;
		delexpn(c);
		replaceexpn(en, pow);
		return;
	}
	if (en->next[0]->type == 4) {
		if (iszero(en->next[0]->retu)) {
			if (en->next[1]->type == 4 && iszero(en->next[1]->retu)) return;
		}
		if (isone(en->next[0]->retu)) {
			en->retu = v("1");
			en->type = 4;
			en->prop = 1;
			return;
		}
	}
	if (en->next[1]->type != 4) {
		if (en->next[0]->ip != NULL && en->next[0]->type != 4) {
			r = en->next[0]->ip;
			n = newproditemset();
			if (!isone(r->coeff)) firstaddtoproditemset(n, enep(connect(ex("("),connect(evar(r->coeff),connect(ex(")^("),connect(copynum(en->next[1]->ep),ex(")"))))),pvl), '*', 0, pvl);
			while ((r = r->next) != NULL) {
				pco = envar(r->coeff);
				c = caspro(pco, en->next[1], pvl);
				pco->retu = NULL;
				delexpn(pco);
				firstaddtoproditemset(n, enep(connect(ex("("), connect(copynum(r->en->ep), connect(ex(")^("), connect(c->ep, ex(")"))))), pvl), '*', 0, pvl);
				c->ep = NULL;
				delexpn(c);
			}
			en->ip = n;
			en->type = 5;
			if (en->pre == NULL || (en->pre->func[0] != '*' && en->pre->func[0] != '/')) {
				expproditemset(en->ip, &num, &exp);
				en->prop = propproditem(en->ip);
				if (num == NULL) {
					delnum(en->ep); en->ep = exp;
					return;
				}
				delnum(en->ep);
				en->ep = connect(num, exp);
			}
			return;
		}
		return;
	}
	if (iszero(en->next[1]->retu)) {
		en->retu = v("1");
		en->type = 4;
		en->prop = 1;
		return;
	}
	if (en->next[0]->type == 3 || en->next[0]->type == 5) {
		if(isone(en->next[1]->retu)){
			delnum(en->ep);
			en->ep = copynum(en->next[0]->ep);
			en->it = en->next[0]->it;
			en->ip = en->next[0]->ip;
			en->next[0]->it = NULL;
			en->next[0]->ip = NULL;
			strcpy_s(en->func, NAME_LEN, en->next[0]->func);
			en->retu = copyvar(en->next[0]->retu);
			en->type = en->next[0]->type;
			en->prop = en->next[0]->prop;
			return;
		}
		if (ispositiveinteger(en->next[1]->retu)) {
			k = vartoint(en->next[1]->retu);
			if (k > POWERMAX) {
				en->ip = newproditemset();
				addtoproditemset(en->ip, en->next[0], copyvar(en->next[1]->retu), '*', 0, pvl);
				en->type = 5;
				return;
			}
			c = enep(copynum(en->next[0]->ep), pvl);
			pow = caspowerint(c, k, pvl);
			delexpn(c);
/*			temp = addoutba(copynum(en->next[0]->ep),'(',')'); p = topnum(temp);
			for (i = 1; i < k; i++) {
				p = calldigt(p, '*', 'n');
				q = addoutba(copynum(en->next[0]->ep), '(', ')');
				p->next = q;
				q->pre = p;
				p = topnum(q);
			}
			enprod = newexpn();
			defineexpn(enprod, temp);
			calculate(enprod, pvl);*/
			replaceexpn(en, pow);
			return;
		}
		en->ip = newproditemset();
		addtoproditemset(en->ip, en->next[0], copyvar(en->next[1]->retu), '*', 0, pvl);
		en->type = 5;
		return;
	}
	if (en->next[0]->type != 4) return;
	if (ispositiveinteger(en->next[1]->retu)|| iszero(en->next[1]->retu)) {
		en->retu = powerint(en->next[0]->retu, vartoint(en->next[1]->retu));
		en->type = 4;
		return;
	}
	vacu = varname("acu", *pvl);
	if (vacu == NULL) {
		printerr(416);
		return;
	}
	acu = vartoint(vacu);
	if (isnegaone(en->next[1]->retu)) {
		en->retu = rev(en->next[0]->retu, acu);
		en->type = 4;
		return;
	}
	en->retu = power(en->next[0]->retu, en->next[1]->retu, acu);
	if (en->retu != NULL) en->type = 4;
}
void calcequal(expn en, varlist* pvl) {
	int k, i;
	varlist left;
	expr q, f;
	expn n;
	char str[NAME_LEN];
	if (en->next[0] == NULL || en->next[1] == NULL) {
		printerr(415);
		return;
	}
	if (en->next[0]->type == 4) return;
	k = 0;
	if (en->next[0]->name[0] == 0) {
		if (lennum(en->next[0]->ep) > NAME_LEN) return;
		exprtostr(en->next[0]->ep, str);
		strcpy(en->next[0]->name, NAME_LEN, str);
	}
	else if (en->next[0]->next[0] != NULL) {
		i = 0;
		if (en->next[0]->next[0]->func[0] != ',' || en->next[0]->next[0]->next[0] == NULL) n = en->next[0]->next[0];
		else n = en->next[0]->next[0]->next[0];
		if (n->name[0] == 0) i = 1;
		k++;
		while ((n = arraynext(n)) != NULL) {
			if (n->name[0] == 0) {
				i = 1; break;
			}
			k++;
		}
		if (i == 1) {
			k = 0;
			if (lennum(en->next[0]->ep) > NAME_LEN) return;
			exprtostr(en->next[0]->ep, str);
			strcpy(en->next[0]->name, NAME_LEN, str);
		}
		if (k > FUNCVAR_MAX) {
			printerr(424);
			return;
		}
	}
	left = pvarname(en->next[0]->name, *pvl);
	if (left == NULL) left = insertvar(NULL, en->next[0]->name, pvl);
	delvar(left->x);
	left->x = NULL;
	delnum(left->ep);
	left->ep = NULL;
	if (en->next[1]->type == 4) {
		left->x = copyvar(en->next[1]->retu);
		left->type = -1;
		en->retu = copyvar(en->next[1]->retu);
		en->type = 4;
		en->prop = 1;
		return;
	}
	if (k == 0) {
//		left->ep = copyoriginal(en->next[1]);
		left->ep = copynum(en->next[1]->ep);
		left->type = 0;
		delnum(en->ep);
		en->ep = copynum(en->next[1]->ep);
		en->type = 5;
		en->prop = en->next[1]->prop;
		return;
	}
	i = 1;
	if (en->next[0]->next[0]->func[0] != ',' || en->next[0]->next[0]->next[0] == NULL) n = en->next[0]->next[0];
	else n = en->next[0]->next[0]->next[0];
//	f = copyoriginal(en->next[1]);
	f = copynum(en->next[1]->ep);
	q = newnum(); q->d = 1; insertdigt(q, i, 'n');
	f = replace(f, n->ep, q);
	delnum(q);
	while (i < k) {
		i++;
		n = arraynext(n);
		q = newnum(); q->d = 1; insertdigt(q, i, 'n');
		f = replace(f, n->ep, q);
		delnum(q);
	}
	left->ep = f;
	left->type = k;
	delnum(en->ep);
	en->ep = copynum(en->next[1]->ep);
	en->type = 5;
	en->prop = en->next[1]->prop;
}
void calcinp(expn en, varlist* pvl) {
	int k, i;
	varlist left;
	expr enter = NULL;
	expr q, f;
	expn en_enter, n;
	char str[NAME_LEN];
	if (en->next[0] == NULL) {
		printerr(415); 
		return;
	}
	if (en->next[0]->type == 4) return;
	k = 0;
	if (en->next[0]->name[0] == 0) {
		if (lennum(en->next[0]->ep) > NAME_LEN) return;
		exprtostr(en->next[0]->ep, str);
		strcpy(en->next[0]->name, NAME_LEN, str);
	}
	else if (en->next[0]->next[0] != NULL) {
		i = 0;
		if (en->next[0]->next[0]->func[0] != ',' || en->next[0]->next[0]->next[0] == NULL) n = en->next[0]->next[0];
		else n = en->next[0]->next[0]->next[0];
		if (n->name[0] == 0) i = 1;
		k++;
		while ((n = arraynext(n)) != NULL) {
			if (n->name[0] == 0) {
				i = 1; break;
			}
			k++;
		}
		if (i == 1) {
			k = 0;
			if (lennum(en->next[0]->ep) > NAME_LEN) return;
			exprtostr(en->next[0]->ep, str);
			strcpy(en->next[0]->name, NAME_LEN, str);
		}
		if (k > FUNCVAR_MAX) {
			printerr(424);
			return;
		}
	}
	while (enter == NULL) {
#ifdef COLOR_IO
		printf("%s="COLOR_INPUT, en->next[0]->name);
		enter = getline();
		printf(COLOR_OUTPUT);
#else
		printf("%s=", en->next[0]->name);
		enter = getline();
#endif
	}
	en_enter = enep(enter, pvl);
	left = pvarname(en->next[0]->name, *pvl);
	if (left == NULL) left = insertvar(NULL, en->next[0]->name, pvl);
	delvar(left->x);
	left->x = NULL;
	delnum(left->ep);
	left->ep = NULL;
	if (en_enter->type == 4) {
		left->x = copyvar(en_enter->retu);
		left->type = -1;
		en->retu = en_enter->retu;
		en->type = 4;
		en->prop = 1;
		en_enter->retu = NULL;
		delexpn(en_enter);
		return;
	}
	if (k == 0) {
	//left->ep = copyoriginal(en->next[1]);
		left->ep = copynum(en_enter->ep);
		left->type = 0;
		delnum(en->ep);
		en->ep = en_enter->ep;
		en->type = 5;
		en->prop = en_enter->prop;
		en_enter->ep = NULL;
		delexpn(en_enter);
		return;
	}
	i = 1;
	if (en->next[0]->next[0]->func[0] != ',' || en->next[0]->next[0]->next[0] == NULL) n = en->next[0]->next[0];
	else n = en->next[0]->next[0]->next[0];
	//	f = copyoriginal(en->next[1]);
	f = copynum(en_enter->ep);
	q = newnum(); q->d = 1; insertdigt(q, i, 'n');
	f = replace(f, n->ep, q);
	delnum(q);
	while (i < k) {
		i++;
		n = arraynext(n);
		q = newnum(); q->d = 1; insertdigt(q, i, 'n');
		f = replace(f, n->ep, q);
		delnum(q);
	}
	left->ep = f;
	left->type = k;
	delnum(en->ep);
	en->ep = en_enter->ep;
	en->type = 5;
	en->prop = en_enter->prop;
	en_enter->ep = NULL;
	delexpn(en_enter);
}
void calcrun(expn en, varlist* pvl) {
	char fn[NAMEFILE_LEN];
	stc fep;
	varlist ans;
	if (en->next[0] == NULL) {
		printerr(415); 
		return;
	}
	exprtostr(en->next[0]->ep, fn);
	fep = open(fn);
	if (fep == NULL) return;
	calcstc(fep, pvl);
	delnum(fep);
	ans = pvarname("ans", *pvl);
	if (ans != NULL) {
		delnum(en->ep);
		en->ep = copynum(ans->ep);
		en->retu = copyvar(ans->x);	
		if (ans->type == -1) en->type = 4;
		else en->type = 5;
	}
}
void calce(expn en, varlist vl) {
	int acu;
	var vacu;
	if (en->next[0] == NULL) {
		printerr(415); 
		return;
	}
	if (!istype(en->next[0], 4)) return;
	vacu = varname("acu", vl);
	if (vacu == NULL) {
		printerr(416); 
		return;
	}
	acu = vartoint(vacu);
	en->retu = e(vartoint(en->next[0]->retu));
	if (en->retu != NULL) en->type = 4;
}
void calcpi(expn en, varlist vl) {
	if (en->next[0] == NULL) {
		printerr(415); 
		return;
	}
	if (!istype(en->next[0], 4)) return;
	en->retu = pi(vartoint(en->next[0]->retu));
	if (en->retu != NULL) en->type = 4;
}
void afcalcd(var f(var,var,int),expn en, varlist vl) {
	int acu;
	var vacu;
	if (lenarray(en->next[0])!=2) {
		printerr(425); 
		return;
	}
	if (!istype(en->next[0]->next[0], 4)|| !istype(en->next[0]->next[1], 4)) return;
	vacu = varname("acu", vl);
	if (vacu == NULL) {
		printerr(416); 
		return;
	}
	acu = vartoint(vacu);
	en->retu = f(en->next[0]->next[0]->retu, en->next[0]->next[1]->retu, acu);
	if (en->retu != NULL) en->type = 4;
}
void afcalcdop(var f(var, var, int), expn en, varlist vl) {
	int acu;
	var vacu;
	if (en->next[0] == NULL || en->next[1] == NULL) {
		printerr(415);
		return;
	}
	if (!istype(en->next[0], 4) || !istype(en->next[1], 4)) return;
	vacu = varname("acu", vl);
	if (vacu == NULL) {
		printerr(416);
		return;
	}
	acu = vartoint(vacu);
	en->retu = f(en->next[0]->retu, en->next[1]->retu, acu);
	if (en->retu != NULL) en->type = 4;
}
void calcapowerint(expn en, varlist vl) {
	int acu;
	var vacu;
	if (lenarray(en->next[0]) != 2) {
		printerr(425);
		return;
	}
	if (!istype(en->next[0]->next[0], 4) || !istype(en->next[0]->next[1], 4)) return;
	vacu = varname("acu", vl);
	if (vacu == NULL) {
		printerr(416);
		return;
	}
	acu = vartoint(vacu);
	en->retu = apowerint(en->next[0]->next[0]->retu, vartoint(en->next[0]->next[1]->retu), acu);
	if (en->retu != NULL) en->type = 4;
}
void fcalc(var f(var),expn en, varlist vl) {
	if (en->next[0] == NULL) {
		printerr(415); 
		return;
	}
	if (!istype(en->next[0], 4)) return;
	en->retu = f(en->next[0]->retu);
	if (en->retu != NULL) en->type = 4;
}
void afcalc(var f(var, int), expn en, varlist vl) {
	int acu;
	var vacu;
	if (en->next[0] == NULL) {
		printerr(415); 
		return;
	}
	if (!istype(en->next[0], 4)) return;
	vacu = varname("acu", vl);
	if (vacu == NULL) {
		printerr(416); 
		return;
	}
	acu = vartoint(vacu);
	en->retu = f(en->next[0]->retu, acu);
	if (en->retu != NULL) en->type = 4;
}
void calcdel(expn en, varlist* pvl) {
	char name[NAME_LEN];
	if (en->next[0] == NULL) {
		printerr(415); 
		return;
	}
	if (lennum(en->next[0]->ep) > NAME_LEN) {
		*pvl = removevar(en->next[0]->name, *pvl);
		return;
	}
	else {
		exprtostr(en->next[0]->ep, name);
		if (pvarname(name, *pvl) != NULL) {
			*pvl = removevar(name, *pvl);
		}
		else *pvl = removevar(en->next[0]->name, *pvl);
	}
	/*if (en->next[0]->name[0] == 0) {
		printerr(7);
		return;
	}*/
}
void calcisdef(expn en, varlist* pvl) {
	varlist p;
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	if (en->next[0]->name[0] == 0) {
		printerr(7);
		return;
	}
	p = pvarname(en->next[0]->name, *pvl);
	if (p == NULL) en->retu = newvar();
	else en->retu = v("1");
	en->type = 4;
}
void calcran(expn en, varlist vl) {
	if (lenarray(en->next[0]) != 2) {
		printerr(425);
		return;
	}
	if (!istype(en->next[0]->next[0], 4) || !istype(en->next[0]->next[1], 4)) return;
	if (compnum(en->next[0]->next[0]->retu->re, en->next[0]->next[1]->retu->re) > 0) {
		printerr(8);
		return;
	}
	en->retu = newvar();
	delnum(en->retu->re);
	en->retu->re = _rand(en->next[0]->next[0]->retu->re, en->next[0]->next[1]->retu->re);
	en->type = 4;
}
int istype(expn ep, int n) {
	if (ep == NULL) return 0;
	if (ep->type == n) return 1;
	else return 0;
}
int ispositiveinteger(var x) {
	digt* p;
	number zero = newnum();
	if (compnum(x->im, zero) != 0 || compnum(x->re, zero) == 0) {
		delnum(zero);
		return 0;
	}
	delnum(zero);
	if (x->sgr == -1) return 0;
	p = x->re;
	while (p->pre != NULL) {
		p = p->pre;
		if (p->d != 0) return 0;
	}
	return 1;
}
int isnegaone(var x) {
	int k;
	number zero, one;
	if (x->sgr == 1) return 0;
	zero = newnum();
	if (compnum(x->im, zero) != 0) {
		delnum(zero);
		return 0;
	}
	delnum(zero);
	one = num("1");
	if (compnum(x->re, one) == 0) k = 1;
	else k = 0;
	delnum(one);
	return k;
}
int isone(var x) {
	int k;
	number zero, one;
	if (x->sgr == -1) return 0;
	zero = newnum();
	if (compnum(x->im, zero) != 0) {
		delnum(zero);
		return 0;
	}
	delnum(zero);
	one = num("1");
	if (compnum(x->re, one) == 0) k = 1;
	else k = 0;
	delnum(one);
	return k;
}
void calchelp(expn en, varlist vl) {
	printf("MathLab "SUB_TITLE"\nVersion:"VERSION"\nA simple calculator for mathematics and natural sciences.\nRead MathLab User's Guide for further information.\nDeveloped by 杨洪权(Hongquan Yang)\n2015-2021\n");
}
void calcstrplus(expn en, varlist vl) {
	expr a, b;
	digt *r, *s;
	if (lenarray(en->next[0])!=2) {
		printerr(425);
		return;
	}
	a = removeoutqu(copynum(en->next[0]->next[0]->ep));
	b = removeoutqu(copynum(en->next[0]->next[1]->ep));
	r = s = NULL;
	if (a != NULL) r = topnum(a);
	if (b != NULL) s = bottomnum(b);
	if (r != NULL) r->next = s;
	if (s != NULL) s->pre = r;
	delnum(en->ep);
	if (a != NULL) en->ep = a;
	else en->ep = b;
	if (en->ep == NULL) en->ep = ex("\"\"");
	else addoutba(en->ep, '\"', '\"');
	en->type = 5;
}
void calcstrreplace(expn en, varlist vl) {
	expr ep, b, a;
	if (lenarray(en->next[0]) != 3) {
		printerr(425);
		return;
	}
	ep = removeoutqu(copynum(en->next[0]->next[0]->ep));
	b = removeoutqu(copynum(en->next[0]->next[1]->next[0]->ep));
	a = removeoutqu(copynum(en->next[0]->next[1]->next[1]->ep));
	ep = replace(ep, b, a);
	delnum(en->ep);
	delnum(b);
	delnum(a);
	en->ep = ep;
	if (en->ep == NULL) en->ep = ex("\"\"");
	else addoutba(en->ep, '\"', '\"');
	en->type = 5;
}
void calctoexp(expn en, varlist* pvl) {
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	if (en->next[0]->type == 4) return;
	if (en->next[0]->ep == NULL || en->next[0]->ep->d != '\"') return;
	if (en->next[0]->ep->next == NULL || en->next[0]->ep->next->d == en->next[0]->ep->d) return;
	delnum(en->ep);
	en->ep = removeoutqu(en->next[0]->ep);
	en->next[0]->ep = NULL;
	delexpn(en->next[0]);
	delexpn(en->next[1]);
	en->next[0] = NULL;
	en->next[1] = NULL;
	delvar(en->retu);
	en->retu = NULL;
	en->name[0] = en->func[0] = 0;
	en->it = en->ip = NULL;
	en->prop = 0;
	en->type = 1;
	calculate(en, pvl);
}
void calctostr(expn en, varlist vl) {
	digt* p;
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	if (en->next[0]->type == 4) {
		en->ep = addoutba(evar(en->next[0]->retu), '\"', '\"');
		en->type = 5;
		return;
	}
	p = en->next[0]->ep;
	do {
		if (p->d == '\"') return;
	} while ((p = p->next) != NULL);
	en->ep = copynum(addoutba(en->next[0]->ep,'\"','\"'));
	en->type = 5;
}
void calcstrcopy(expn en, varlist vl) {
	expr ep, str;
	int start, end;
	digt* sd, * ed;
	if (lenarray(en->next[0]) != 3) {
		printerr(425);
		return;
	}
	if (!istype(en->next[0]->next[1]->next[0], 4) || !istype(en->next[0]->next[1]->next[1], 4)) return;
	start = vartoint(en->next[0]->next[1]->next[0]->retu);
	end = vartoint(en->next[0]->next[1]->next[1]->retu);
	str = removeoutqu(copynum(en->next[0]->next[0]->ep));
	if (end < start || start<1 || end>lennum(str)) {
		printerr(10);
		return;
	}
	sd = str;
	ed = str;
	for (; start > 1; start--) sd = sd->next;
	for (; end > 1; end--) ed = ed->next;
	ep = copyexpr(sd, ed);
	delnum(str);
	delnum(en->ep);
	en->ep = ep;
	addoutba(en->ep, '\"', '\"');
	en->type = 5;
}
void calcstrcmp(expn en, varlist vl) {
	expr a, b;
	if (lenarray(en->next[0]) != 2) {
		printerr(425);
		return;
	}
	a = removeoutqu(copynum(en->next[0]->next[0]->ep));
	b = removeoutqu(copynum(en->next[0]->next[1]->ep));
	if (compexpr(a, b) == 0) en->retu = newvar();
	else en->retu = v("1");
	delnum(a); delnum(b);
	en->type = 4;
}
void calcstrsearch(expn en, varlist vl) {
	var ans, one, temp;
	expr a, b;
	digt* p;
	if (lenarray(en->next[0]) != 2) {
		printerr(425);
		return;
	}
	p = a = removeoutqu(copynum(en->next[0]->next[0]->ep));
	b = removeoutqu(copynum(en->next[0]->next[1]->ep));
	ans = v("1");
	one = v("1");
	while (p != NULL) {
		if (istheexpr(p, b)) break;
		p = p->next;
		temp = plus(ans, one);
		delvar(ans);
		ans = temp;
	}
	delvar(one);
	if (p == NULL) {
		delvar(ans);
		en->retu = newvar();
	}
	else en->retu = ans;
	delnum(a); delnum(b);
	en->type = 4;
}
void calcstrlen(expn en, varlist vl) {
	expr a;
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	a = removeoutqu(copynum(en->next[0]->ep));
	en->retu = intvar(lennum(a));
	en->type = 4;
	delnum(a);
}
void calcsave(expn en, varlist vl) {
	char fn[NAMEFILE_LEN];
	expr ep;
	if (lenarray(en->next[0]) != 2) {
		printerr(425);
		return;
	}
	ep = en->next[0]->next[0]->ep;
	exprtostr(en->next[0]->next[1]->ep, fn);
	save(ep, fn);
}
void calcopen(expn en, varlist vl) {
	char fn[NAMEFILE_LEN];
	expr ep;
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	exprtostr(en->next[0]->ep, fn);
	ep = open(fn);
	if (ep == NULL) {
		printerr(604);
		return;
	}
	delnum(en->ep);
	en->ep = ep;
	en->type = 5;
}
void calcfiledel(expn en, varlist vl) {
	char fn[NAMEFILE_LEN];
	char head[NAMEFILE_LEN + 4] = "del ";
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	exprtostr(en->next[0]->ep, fn);
	strcat_s(head, NAMEFILE_LEN + 4, fn);
	system(head);
}
void calccmd(expn en, varlist vl) {
	char fn[MAX_STR];
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	exprtostr(en->next[0]->ep, fn);
	system(fn);
}
void calcpr(expn en, varlist vl) {
	int i, k, l;
	expn p;
	if (lenarray(en->next[0]) != 2 ) {
		printerr(425);
		return;
	}
	if (en->next[0]->next[1]->type != 4) return;
	k = vartoint(en->next[0]->next[1]->retu);
	l = lenarray(en->next[0]->next[0]);
	if (k < 1 || k>l) return;
	if (l == 1) {
		if (k != 1) return;
		replaceexpn(en, en->next[0]->next[0]);
		return;
	}
	p = en->next[0]->next[0]->next[0];
	for (i = 1; i < k; i++) {
		p = arraynext(p);
		if (p == NULL) return;
	}
	replaceexpn(en, p);
}
void calcsum(expn en, varlist* pvl) {
	var start, end, ans, temp, one;
	varlist vs;
	expn epn;
	if (lenarray(en->next[0]) != 4) {
		printerr(425);
		return;
	}
	if (en->next[0]->next[1]->next[0]->name[0] == 0) {
		printerr(11);
		return;
	}
	if (!istype(en->next[0]->next[1]->next[1]->next[0], 4) || !istype(en->next[0]->next[1]->next[1]->next[1], 4)) return;
	start = copyvar(en->next[0]->next[1]->next[1]->next[0]->retu);
	end = copyvar(en->next[0]->next[1]->next[1]->next[1]->retu);
	ans = newvar();
	one = v("1");
	while (compreal(start, end) <= 0) {
		vs = pvarname(en->next[0]->next[1]->next[0]->name, *pvl);
		if (vs == NULL) insertvar(copyvar(start), en->next[0]->next[1]->next[0]->name, pvl);
		else {
			delnum(vs->ep);
			vs->ep = NULL;
			delvar(vs->x);
			vs->x = copyvar(start);
			vs->type = -1;
		}
		epn = newexpn();
		defineexpn(epn, copynum(en->next[0]->next[0]->ep));
		calculate(epn, pvl);
		if (epn->retu != NULL) {
			temp = ans;
			ans = plus(ans, epn->retu);
			delvar(temp);
		}
		delexpn(epn);
		temp = start;
		start = plus(start, one);
		delvar(temp);
	}
	delvar(start);
	delvar(end);
	delvar(one);
	en->retu = ans;
	en->type = 4;
	en->prop = 1;
}
void calcprod(expn en, varlist* pvl) {
	var start, end, ans, temp, one;
	varlist vs;
	expn epn;
	if (lenarray(en->next[0]) != 4) {
		printerr(425);
		return;
	}
	if (en->next[0]->next[1]->next[0]->name[0] == 0) {
		printerr(11);
		return;
	}
	if (!istype(en->next[0]->next[1]->next[1]->next[0], 4) || !istype(en->next[0]->next[1]->next[1]->next[1], 4)) return;
	start = copyvar(en->next[0]->next[1]->next[1]->next[0]->retu);
	end = copyvar(en->next[0]->next[1]->next[1]->next[1]->retu);
	ans = v("1");
	one = v("1");
	while (compreal(start, end) <= 0) {
		vs = pvarname(en->next[0]->next[1]->next[0]->name, *pvl);
		if (vs == NULL) insertvar(copyvar(start), en->next[0]->next[1]->next[0]->name, pvl);
		else {
			delnum(vs->ep);
			vs->ep = NULL;
			delvar(vs->x);
			vs->x = copyvar(start);
			vs->type = -1;
		}
		epn = newexpn();
		defineexpn(epn, copynum(en->next[0]->next[0]->ep));
		calculate(epn, pvl);
		if (epn->retu != NULL) {
			temp = ans;
			ans = mult(ans, epn->retu);
			delvar(temp);
		}
		delexpn(epn);
		temp = start;
		start = plus(start, one);
		delvar(temp);
	}
	delvar(start);
	delvar(end);
	delvar(one);
	en->retu = ans;
	en->type = 4;
}
void calctypevar(expn en, varlist vl) {
	varlist p;
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	if (en->next[0]->name[0] == 0) {
		printerr(7);
		return;
	}
	p = pvarname(en->next[0]->name, vl);
	en->type = 4;
	en->prop = 1;
	if (p == NULL) {
		en->retu = v("-2");
		return;
	}
	if (p->type == -1) {
		en->retu = v("-1");
		return;
	}
	en->retu = intvar(p->type);
}
void calctypeexp(expn en, varlist vl) {
	int t;
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	t = en->next[0]->type;
	if (t == 0) en->retu = v("0");
	if (t == 1) en->retu = v("1");
	if (t == 2) en->retu = v("2");
	if (t == 3) en->retu = v("3");
	if (t == 4) en->retu = v("4");
	if (t == 5) en->retu = v("5");
	en->type = 4;
	en->prop = 1;
}
void calcrefvl(expn en, varlist* pvl) {
	delvarlist(*pvl);
	*pvl = newvarlist();
}
void calculate(expn en, varlist* pvl) {
	varlist vl, p;
//CANCEL ITERATION_MAX
//	if (iteration_number > ITERATION_MAX) return;
	if (en->type == 0) {
		//printerr(417);
		return;
	}
	if (en->type < 3) alllogicalize(en, pvl);
	if (en->type < 3) {
		//printerr(418);
		return;
	}
	if (en->type > 3) {
		decoration(en);
		return;
	}
	if (en->func[0] == ' ') {
		if (en->next[0] != NULL) alldecoration(en->next[0]);
		if (en->next[1] != NULL) alldecoration(en->next[1]);
		calcspace(en, pvl);
		decoration(en);
		return;
	}
	if (en->next[0] != NULL) calculate(en->next[0], pvl);
	if (en->next[1] != NULL) calculate(en->next[1], pvl);
	vl = *pvl;
	if ((p = pvarnameep(en->ep, vl)) != NULL) {
		if (en->pre != NULL && (!strcmp(en->pre->func, "del") || !strcmp(en->pre->func, "typevar") || !strcmp(en->pre->func, "isdef"))) {
			decoration(en);
			return;
		}
		//CANCEL ITERATION_MAX
		//iteration_number++;
		calcfunc(p, en, pvl);
		decoration(en);
		return;
	}
	if ((p = pvarname(en->func, vl)) != NULL) {
		if (en->pre != NULL && (!strcmp(en->pre->func, "del") || !strcmp(en->pre->func, "typevar") || !strcmp(en->pre->func, "isdef"))) {
			decoration(en);
			return;
		}
		//CANCEL ITERATION_MAX
		//iteration_number++;
		calcfunc(p, en, pvl);
		decoration(en);
		return;
	}
	if (en->func[0] == '@') calcprint(en, vl);
	if (en->func[0] == '+' || en->func[0] == '-') casplus(en, vl);
	if (en->func[0] == '*' || en->func[0] == '/') { casprod(en, pvl); decoration(en); return; }
	if (en->func[0] == '^') { calcpower(en, pvl); decoration(en); return; }
	if (en->func[0] == '>') calcbi(en, vl);
	if (en->func[0] == '<') calcsm(en, vl);
	if (en->func[0] == '?') calcqu(en, vl);
	if (en->func[0] == '&') calcand(en, vl);
	if (en->func[0] == '|') calcor(en, vl);
	if (en->func[0] == '!') calcnot(en, vl);
	if (en->func[0] == '%') calcremain(en, vl);
	if (strcmp(en->func, "exp") == 0) calcexp(en, vl);
	if (strcmp(en->func, "ln") == 0) calcln(en, vl);
	if (strcmp(en->func, "sin") == 0) afcalc(_sin, en, vl);
	if (strcmp(en->func, "cos") == 0) afcalc(_cos, en, vl);
	if (strcmp(en->func, "tan") == 0) afcalc(_tan, en, vl);
	if (strcmp(en->func, "en") == 0) calce(en, vl);
	if (strcmp(en->func, "pin") == 0) calcpi(en, vl);
	if (strcmp(en->func, "sqrt") == 0) calcsqrt(en, pvl);
	if (strcmp(en->func, "log") == 0) afcalcd(_log, en, vl);
	if (strcmp(en->func, "sinh") == 0) afcalc(_sinh, en, vl);
	if (strcmp(en->func, "cosh") == 0) afcalc(_cosh, en, vl);
	if (strcmp(en->func, "tanh") == 0) afcalc(_tanh, en, vl);
	if (strcmp(en->func, "arctan") == 0) afcalc(arctan, en, vl);
	if (strcmp(en->func, "arcsin") == 0) afcalc(arcsin, en, vl);
	if (strcmp(en->func, "arccos") == 0) afcalc(arccos, en, vl);
	if (strcmp(en->func, "apowerint") == 0) calcapowerint(en, vl);
	if (strcmp(en->func, "help") == 0) calchelp(en, vl);
	if (strcmp(en->func, "fact") == 0) fcalc(factorial, en, vl);
	if (strcmp(en->func, "real") == 0) fcalc(realpart, en, vl);
	if (strcmp(en->func, "imag") == 0) fcalc(imagpart, en, vl);
	if (strcmp(en->func, "conj") == 0) fcalc(conjc, en, vl);
	if (strcmp(en->func, "floor") == 0) fcalc(_floor, en, vl);
	if (strcmp(en->func, "ceil") == 0) fcalc(_ceil, en, vl);
	if (strcmp(en->func, "abs") == 0) afcalc(_abs, en, vl);
	if (strcmp(en->func, "ran") == 0) calcran(en, vl);
	if (strcmp(en->func, "strplus") == 0) calcstrplus(en, vl);
	if (strcmp(en->func, "strreplace") == 0) calcstrreplace(en, vl);
	if (strcmp(en->func, "toexp") == 0) {
		calctoexp(en, pvl);
		if (en->type < 3) return;
	}
	if (strcmp(en->func, "tostr") == 0) calctostr(en, vl);
	if (strcmp(en->func, "strcopy") == 0) calcstrcopy(en, vl);
	if (strcmp(en->func, "strcmp") == 0) calcstrcmp(en, vl);
	if (strcmp(en->func, "strsearch") == 0) calcstrsearch(en, vl);
	if (strcmp(en->func, "strlen") == 0) calcstrlen(en, vl);
	if (strcmp(en->func, "save") == 0) calcsave(en, vl);
	if (strcmp(en->func, "open") == 0) calcopen(en, vl);
	if (strcmp(en->func, "filedel") == 0) calcfiledel(en, vl);
	if (strcmp(en->func, "cmd") == 0) calccmd(en, vl);
	if (strcmp(en->func, "pr") == 0) calcpr(en, vl);
	if (en->func[0] == '=') calcequal(en, pvl);
	if (en->func[0] == ':') calcinp(en, pvl);
	if (strcmp(en->func, "sum") == 0) calcsum(en, pvl);
	if (strcmp(en->func, "prod") == 0) calcprod(en, pvl);
	if (strcmp(en->func, "del") == 0) calcdel(en, pvl);
	if (strcmp(en->func, "isdef") == 0) calcisdef(en, pvl);
	if (strcmp(en->func, "run") == 0) calcrun(en, pvl);
	if (strcmp(en->func, "cls") == 0) system("cls");
	if (strcmp(en->func, "exit") == 0) exit(0);
	if (strcmp(en->func, "typevar") == 0) calctypevar(en, vl);
	if (strcmp(en->func, "typeexp") == 0) calctypeexp(en, vl);
	if (strcmp(en->func, "restart") == 0) calcrefvl(en, pvl);
	if (strcmp(en->func, "diff") == 0) casdiff(en, pvl);
	if (strcmp(en->func, "tovar") == 0) {
		//CANCEL ITERATION_MAX
		//iteration_number++;
		calcname(en, pvl);
		decoration(en);
		return;
	}
	if (strcmp(en->func, "arraylen") == 0) calcarraylen(en, vl);
	if (strcmp(en->func, "varlist") == 0) dispvarlist(vl);
	decoration(en);
}
void calc(expn en, varlist* pvl) {
	varlist ans;
	if (en->type == 0) {
		//printerr(417);
		return;
	}
	//CANCEL ITERATION_MAX
	//iteration_number = 0;
	calculate(en, pvl);
	//CANCEL ITERATION_MAX
/*	if (iteration_number > ITERATION_MAX) {
		printerr(420);
		if (strcmp(en->func, "del") == 0 && en->next[0] != NULL && en->next[0]->name[0] != 0) {
			printf("- Do you want to delete the variable '%s'?\n- ", en->next[0]->name);
			if (getyesornot()) {
				*pvl = removevar(en->next[0]->name, *pvl);
				printf("Compelete.\n");
			}
		}
	}*/
	ans = pvarname("ans", *pvl);
	if (ans != NULL) {
		*pvl = removevar("ans", *pvl);
		switch (en->type)
		{
		case 4:insertvar(copyvar(en->retu), "ans", pvl); break;
		case 5:case 3:insertexpr(copynum(en->ep), "ans", pvl); break;
		case 2:case 1:insertexpr(addoutba(copynum(en->ep), '\"', '\"'), "ans", pvl); break;
		default:break;
		}
	}
}
void delexpn(expn en) {
	if (en == NULL) return;
	delexpn(en->next[0]);
	delexpn(en->next[1]);
	delnum(en->ep);
	delvar(en->retu);
	delitemset(en->it);
	delitemset(en->ip);
	free(en);
}
var ce(expr ep, varlist* pvl) {
	expn en = newexpn();
	expr exp = copynum(ep);
	var ans;
	defineexpn(en, exp);
	calculate(en, pvl);
	ans = copyvar(en->retu);
	delexpn(en);
	return ans;
}
var cea(expr ep, varlist* pvl) {
	expn en = newexpn();
	expr exp = copynum(ep);
	var ans;
	defineexpn(en, exp);
	calc(en, pvl);
	ans = copyvar(en->retu);
	delexpn(en);
	return ans;
}
var value(char* str, varlist* pvl) {
	expr ep = ex(str);
	var ans;
	ans = ce(ep, pvl);
	delnum(ep);
	return ans;
}
int isoperator(digt* p) {
	if (p == NULL) return 0;
	if (p->d == ',' || p->d == '!' || p->d == ':' ||p->d == '@'||p->d == '%'||p->d == '^'||p->d == '&'||p->d == '*'||p->d == '-'||p->d == '+'||p->d == '='||p->d == '|'||p->d == '<'||p->d == '>'||p->d == '/'||p->d == '?' || p->d == ' ') return 1;
	return 0;
}
int charcheckforexpr(expr ep) {
	digt* p = bottomnum(ep);
	while (p != NULL) {
		if (!isalphanumber(p) && !isoperator(p) && p->d != '('&&p->d != ')'&&p->d != '['&&p->d != ']') return 0;
		p = p->next;
	}
	return 1;
}
int istheexprnumber(expr ep) {
	int k = 0;
	digt* p = ep;
	if (ep == NULL) return 0;
	p = bottomnum(ep);
	while (p != NULL) {
		if (!(p->next == NULL&&p->d == 'i')) {
			if (!isnumber(p)) return 0;
			if (p->d == '.') k++;
			if (k == 2) return 0;
		}
		p = p->next;
	}
	return 1;
}
int istheexprname(expr ep) {
	digt* p = ep;
	if (ep == NULL) return 0;
	p = bottomnum(ep);
	while (p != NULL) {
		if (!isalphanumber(p)) return 0;
		p = p->next;
	}
	return 1;
}
int isoperative(digt* p) {
	if (!isoperator(p)) return 0;
	if ((issingleoperator(p) && issingle(p)) || (isdoubleoperator(p) && isdouble(p))) return 1;
	return 0;
}
int issingleoperator(digt* p) {
	if (p == NULL) return 0;
	if (p->d == '!' || p->d == ':' || p->d == '@' || p->d == '-' || p->d == '+') return 1;
	return 0;
}
int isdoubleoperator(digt* p) {
	if (p == NULL) return 0;
	if (p->d == ',' || p->d == '@' || p->d == '%' || p->d == '^' || p->d == '&' || p->d == '*' || p->d == '-' || p->d == '+' || p->d == '=' || p->d == '|' || p->d == '<' || p->d == '>' || p->d == '/' || p->d == '?' || p->d == ' ') return 1;
	return 0;
}
expr replace(expr ep, expr before, expr after) {
	digt* p = ep, *q, *r, *s;
	expr t = ep;
	if (ep == NULL) return NULL;
	if (before == NULL) return ep;
	int i, l = lennum(before);
	while (p != NULL) {
		if (istheexpr(p, before)) {
			q = p->pre;
			for (i = 0; i < l; i++) p = deldigt(p, 'n');
			if (after != NULL) {
				t = copynum(after);
				r = bottomnum(t);
				s = topnum(t);
				r->pre = q; s->next = p;
				if (p != NULL) p->pre = s;
				if (q != NULL) q->next = r;
				ep = t;
			}
			else {
				if (p != NULL) { p->pre = q; ep = p; }
				if (q != NULL) { q->next = p; ep = q; }
				if (p == NULL && q == NULL) return NULL;
			}
		}
		else p = p->next;
	}
	return bottomnum(ep);
}
int istheexpr(digt* p, expr ep) {
	digt* q = ep;
	if (ep == NULL) return 0;
	while (q != NULL) {
		if (p == NULL || p->d != q->d) return 0;
		p = p->next;
		q = q->next;
	}
	return 1;
}
int oppcheckoutba(expr p) {
	expr q = p;
	int count = 0, dount = 0, eount = 0, fount = 0;
	do {
		if (p->d == '\"') fount++;
		p = p->next;
	} while (p != NULL);
	if (fount%2 != 0) {
		printerr(423);
		return 0;
	}
	p = q;
	do {
		if (p->d == '[') dount++;
		if (p->d == ']') dount--;
		if (p->d == '\"') p = nextqu(p);
		p = p->next;
	} while (p != NULL);
	if (dount != 0) {
		printerr(406);
		return 0;
	}
	p = q;
	do {
		if (p->d == '(') count++;
		if (p->d == ')') count--;
		if (p->d == '{') eount++;
		if (p->d == '}') eount--;
		if (p->d == '[') p = opp(p);
		if (p->d == '\"') p = nextqu(p);
		if (p == NULL) {
			printerr(406);
			return 0;
		}
		p = p->next;
	} while (p != NULL);
	if (count != 0) {
		printerr(405);
		return 0;
	}
	if (eount != 0) {
		printerr(422);
		return 0;
	}
	return 1;
}
void resetexpn(expn en) {
	if (en == NULL) return;
	en->type = 0;
	en->prop = 0;
	delnum(en->ep);
	en->ep = NULL;
	delexpn(en->next[0]);
	delexpn(en->next[1]);
	en->next[0] = NULL;
	en->next[1] = NULL;
	delvar(en->retu);
	en->retu = NULL;
	en->func[0] = 0;
	delitemset(en->it);
	delitemset(en->ip);
	en->it = NULL;
	en->ip = NULL;
}
expn definebycopy(expn en, digt* p, digt* q) {
	expn enn = newexpn();
	defineexpn(enn, copyexpr(p, q));
	enn->pre = en;
	enn->pre_s = p;
	enn->pre_e = q;
	enn->type = en->type;
	return enn;
}
expr copyoriginal(expn enn) {
	return copyexpr(enn->pre_s, enn->pre_e);
}
int getprior(expn en) {
	char op;
	if (en == NULL) return 0;
	op = en->func[0];
	if (op == ':') return 1;
	if (op == '!') return 2;
	if (op == '^') return 3;
	if ((op == '+' || op == '-') && en->prop == 3) return 4;
	if (op == '*' || op == '/') return 5;
	if (op == '%') return 6;
	if (op == '+' || op == '-') return 7;
	if (op == '>' || op == '<') return 8;
	if (op == '?') return 9;
	if (op == '&') return 10;
	if (op == '|') return 11;
	if (op == '=') return 12;
	if (op == '@' && en->prop == 3) return 13;
	if (op == '@') return 14;
	if (op == ',') return 15;
	if (op == ' ') return 16;
	return 0;
}
expr expnum(number n) {
	expr ep;
	digt* p, * q;
	if (n == NULL) return NULL;
	ep = newexpr();
	p = ep;
	q = topnum(n);
	while (q->d == 0 && q != n) q = q->pre;
	p->d = q->d + '0';
	while (q->pre != NULL) {
		if (q == n) p = calldigt(p, '.', 'n');
		q = q->pre;
		p = calldigt(p, q->d + '0', 'n');
	}
	return ep;
}
expr evar(var x) {
	expr ep, t;
	number one, zero;
	digt* p;
	int r, i;
	if (x == NULL) return NULL;
	one = num("1"); zero = num("0");
	ep = newexpr(); p = ep;
	r = compnum(x->re, zero);
	i = compnum(x->im, zero);
	if (r) {
		if (x->sgr == -1) p = calldigt(p, '-', 'n');
		t = expnum(x->re);
		p->next = t;
		t->pre = p;
		p = topnum(p);
	}
	if (i) {
		if (x->sgi == -1) p = calldigt(p, '-', 'n');
		else if (r) p = calldigt(p, '+', 'n');
		if (compnum(x->im, one)) {
			t = expnum(x->im);
			p->next = t;
			t->pre = p;
			p = topnum(p);
		}
		p = calldigt(p, 'i', 'n');
	}
	if (r == 0 && i == 0) p = calldigt(p, '0', 'n');
	ep = deldigt(ep, 'n');
	delnum(one);
	delnum(zero);
	return ep;
}
void restorecopy(expn enn,expr ep) {
	digt* p, * q;
	if (enn == NULL || enn->pre == NULL || ep == NULL) return;
	q = ep; p = enn->pre_s;
	q->pre = p->pre;
	if (p->pre != NULL) p->pre->next = q;
	q = topnum(ep); p = enn->pre_e;
	q->next = p->next;
	if (p->next != NULL) p->next->pre = q;
	if (enn->pre->ep == enn->pre_s) enn->pre->ep = ep;
	enn->pre_s->pre = NULL; enn->pre_e->next = NULL;
	p = enn->pre_s;
	enn->pre_s = ep; enn->pre_e = q;
	delnum(p);
}
expr addoutba(expr ep, char a, char b) {
	if (ep == NULL) {
		ep = newnum();
		ep->d = b;
		return calldigt(ep, a, 'p');
	}
	calldigt(topnum(ep), b, 'n');
	return calldigt(ep, a, 'p');
}
void decoration(expn en) {
	int r, s, t, u;
	number zero;
	expr ep;
	if (en->ep == NULL) return;
	if (en->type != 4) {
		en->ep = removeoutadd(en->ep);
		if (en->prop == 2 && en->ep->d != '\"' && topnum(en->ep)->d != '\"' && (en->pre==NULL || (en->pre->func[0] != '=' && en->pre->func[0] != ':'))) en->ep = addoutba(en->ep, '\"', '\"');
	}
	if (en->pre != NULL) {
		if (en->pre->next[0] == en) u = 0;
		else u = 1;
		if (en->type == 4) {
			ep = evar(en->retu);
			zero = newnum();
			r = compnum(en->retu->re, zero);
			s = compnum(en->retu->im, zero);
			delnum(zero);
			if (!((en->retu->sgr == 1 && r && s == 0) || (r == 0 && s && en->retu->sgi == 1) || (t = getprior(en->pre)) > 8||(!r&&!s))) ep = addoutba(ep, '(', ')');
			restorecopy(en, ep);
		}
		else if ((en->type == 3 || en->type == 5) && (en->pre->func[0] != '=' || en->pre->next[1] == NULL || en->pre->next[1] != en)) {
		//else if (en->type == 3 || en->type == 5) {
			t = 1;
			r = getprior(en->pre);
			s = getprior(en);
			if (en->prop == 1 || en->prop == 2 || r == 0 || s == 0 || r > s) t = 0;
			if (r == s && (r == 1 || r == 2 || r == 4 || r == 13 || r == 10 || r == 11)) t = 0;
			if (r == s && ((en->func[0] == '+' && en->pre->func[0] == '+') || (en->func[0] == '*' && en->pre->func[0] == '*'))) t = 0;
			if (r == s && (((r == 3 || r == 12 || r == 15 || r == 16) && u == 1) || (u == 0 && r != 16 &&r != 15 && r != 12 && r != 3))) t = 0;
			if (t) restorecopy(en, addoutba(copynum(en->ep), '(', ')'));
			else restorecopy(en, copynum(en->ep));
		}
	}
}
digt* nextqu(digt* p) {
	p = p->next;
	while (p != NULL && p->d != '\"') p = p->next;
	return p;
}
digt* prequ(digt* p) {
	p = p->pre;
	while (p != NULL && p->d != '\"') p = p->pre;
	return p;
}
expn copyexpn(expn en) {
	digt* p, * q;
	if (en == NULL) return NULL;
	expn e = (expn)malloc(sizeof(struct explist));
	if (e == NULL) {
		printerr(400);
		system("pause");
		exit(0);
	}
	e->type = en->type;
	e->prop = en->prop;
	e->ep = copynum(en->ep);
	e->next[0] = copyexpn(en->next[0]);
	e->next[1] = copyexpn(en->next[1]);
	if (en->next[0] != NULL) {
		e->next[0]->pre = e;
		p = en->ep;
		q = e->ep;
		while (p != NULL && p != en->next[0]->pre_s) {
			p = p->next;
			q = q->next;
		}
		e->next[0]->pre_s = q;
		while (p != NULL && p != en->next[0]->pre_e) {
			p = p->next;
			q = q->next;
		}
		e->next[0]->pre_e = q;
	}
	if (en->next[1] != NULL) {
		e->next[1]->pre = e;
		p = en->ep;
		q = e->ep;
		while (p != NULL && p != en->next[1]->pre_s) {
			p = p->next;
			q = q->next;
		}
		e->next[1]->pre_s = q;
		while (p != NULL && p != en->next[1]->pre_e) {
			p = p->next;
			q = q->next;
		}
		e->next[1]->pre_e = q;
	}
	e->pre = NULL;
	e->pre_e = NULL;
	e->pre_s = NULL;
	e->retu = copyvar(en->retu);
	e->it = copyitemset_id(en->it);
	e->ip = copyitemset_id(en->ip);
	strcpy(e->name, NAME_LEN, en->name);
	strcpy(e->func, NAME_LEN, en->func);
	return e;
}
void replaceexpn(expn en, expn enp) {
	if (enp->pre != NULL) {
		if (enp->pre->next[0] == enp) enp->pre->next[0] = NULL;
		if (enp->pre->next[1] == enp) enp->pre->next[1] = NULL;
	}
	delexpn(en->next[0]);
	delexpn(en->next[1]);
	en->next[0] = enp->next[0];
	en->next[1] = enp->next[1];
	delnum(en->ep);
	en->ep = enp->ep;
	delitemset(en->it);
	delitemset(en->ip);
	en->it = enp->it;
	en->ip = enp->ip;
	strcpy_s(en->func, NAME_LEN, enp->func);
	delvar(en->retu);
	en->retu = enp->retu;
	en->type = enp->type;
	en->prop = enp->prop;
	if (enp->next[0] != NULL) enp->next[0]->pre = en;
	if (enp->next[1] != NULL) enp->next[1]->pre = en;
	free(enp);
}
void calcname(expn en, varlist* pvl) {
	varlist p;
	expr name;
	expn n = NULL;
	expr f, q, a;
	int k, l;
	char str[NAME_LEN];
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	if (en->next[0]->func[0] == ',') {
		if (en->next[0]->next[0] == NULL || en->next[0]->next[1] == NULL) return;
		n = en->next[0]->next[0];
	}
	else n = en->next[0];
	if (n->type == 4) name = evar(n->retu);
	else name = n->ep;
	if (lennum(name) > NAME_LEN) return;
	exprtostr(name, str);
	strcpy(en->name, NAME_LEN, str);
	if (n->type == 4) delnum(name);
	p = pvarname(str, *pvl);
	if (en->next[0]->func[0] != ',') {
		delexpn(en->next[0]);
		en->next[0] = NULL;
	}
	else replaceexpn(en->next[0], en->next[0]->next[1]);
	if (p == NULL || (en->pre != NULL && (en->pre->func[0] == '=' || en->pre->func[0] == ':') && en->pre->next[0] == en)) {
		en->type = 5;
		en->prop = 1;
		return;
	}
	if (p->type == -1) {
		en->retu = copyvar(p->x);
		en->type = 4;
		en->prop = 1;
		return;
	}
	if (p->type > lenarray(en->next[0])) {
		printerr(421);
		return;
	}
	f = copynum(p->ep);
	k = 0; l = p->type;
	if (k < l) {
		k++;
		if (en->next[0]->func[0] != ',' || en->next[0]->next[0] == NULL) n = en->next[0];
		else n = en->next[0]->next[0];
		q = newnum(); q->d = 1; insertdigt(q, k, 'n');
		a = removeoutadd(copynum(n->ep));
		f = replace(f, q, a);
		delnum(a);
		delnum(q);
	}
	while (k < l) {
		k++; n = arraynext(n);
		q = newnum(); q->d = 1; insertdigt(q, k, 'n');
		a = removeoutadd(copynum(n->ep));
		f = replace(f, q, a);
		delnum(a);
		delnum(q);
	}
	resetexpn(en);
	en->ep = f;
	en->type = 1;
	calculate(en, pvl);
}
expn enep(expr ep, varlist* pvl) {
	expn en = newexpn();
	defineexpn(en, ep);
	calculate(en, pvl);
	return en;
}
expr connect(expr a, expr b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	b->pre = topnum(a);
	b->pre->next = b;
	return a;
}
void calcsqrt(expn en, varlist* pvl) {
	if (en->next[0] == NULL) return;
	if (en->next[0]->type == 4) {
		afcalc(_sqrt, en, *pvl);
		return;
	}
	if (en->next[0]->type == 3 || en->next[0]->type == 5) {
		en->ip = newproditemset();
		addtoproditemset(en->ip, en->next[0], v("0.5"), '*', 0, pvl);
		en->type = 5;
		return;
	}
}
void calcln(expn en, varlist vl) {
	expr e;
	expn pow;
	if (en->next[0] == NULL) return;
	if (en->next[0]->type == 4) {
		afcalc(ln, en, vl);
		return;
	}
	e = ex(VAR_E);
	if (en->next[0]->type != 4 && compexpr_sans(en->next[0]->ep, e)) {
		en->retu = v("1");
		en->type = 4;
		delnum(e);
		return;
	}
	if (en->next[0]->next[0] != NULL && !strcmp(en->next[0]->func, "exp")) {
		replaceexpn(en, en->next[0]->next[0]);
		delnum(e);
		return;
	}
	pow = en->next[0];
	if (pow->func[0] == '^' && pow->next[0] != NULL && pow->next[1] != NULL && pow->next[0]->type != 4 && compexpr_sans(pow->next[0]->ep, e)) {
		replaceexpn(en, pow->next[1]);
		delnum(e);
		return;
	}
	if (en->next[0]->ip != NULL&&isone(en->next[0]->ip->coeff)&& en->next[0]->ip->next!=NULL&& en->next[0]->ip->next->next==NULL) {
		pow = en->next[0]->ip->next->en;
		if (pow->type != 4 && compexpr_sans(pow->ep, e)) {
			en->retu = copyvar(en->next[0]->ip->next->coeff);
			en->type = 4;
			delnum(e);
			return;
		}
		if (pow->func[0] == '^' && pow->next[0] != NULL && pow->next[1] != NULL && pow->next[0]->type != 4 && compexpr_sans(pow->next[0]->ep, e)) {
			replaceexpn(en, pow->next[1]);
			delnum(e);
			return;
		}
	}
	delnum(e);
}
void calcexp(expn en, varlist vl) {
	if (en->next[0] == NULL) return;
	if (en->next[0]->type == 4) {
		afcalc(_exp, en, vl);
		return;
	}
	if (en->next[0]->next[0] != NULL && !strcmp(en->next[0]->func, "ln")) {
		replaceexpn(en, en->next[0]->next[0]);
		return;
	}
}
expn envar(var x) {
	expn en;
	if (x == NULL) return NULL;
	en = newexpn();
	en->retu = x;
	en->type = 4;
	en->prop = 1;
	return en;
}
expn arraynext(expn en) {
	if (en->pre == NULL || en->pre->func[0] != ',' || en->pre->next[1] == NULL || en->pre->next[1] == en) return NULL;
	if (en->pre->next[1]->func[0] != ',') return en->pre->next[1];
	return en->pre->next[1]->next[0];
}
int lenarray(expn en) {
	int len = 1;
	if (en == NULL) return 0;
	if (en->next[0] == NULL) return 1;
	else en = en->next[0];
	while ((en = arraynext(en)) != NULL) len++;
	return len;
}
void calcfunc(varlist p, expn en, varlist* pvl) {
	expr f, q, a;
	expn n = NULL;
	int k, l;
	if (en->pre != NULL && (en->pre->func[0] == '=' || en->pre->func[0] == ':') && en->pre->next[0] == en) {
		en->type = 5;
		en->prop = 1;
		return;
	}
	if (p->type == -1) {
		en->retu = copyvar(p->x);
		en->type = 4;
		en->prop = 1;
		return;
	}
	if (p->type > lenarray(en->next[0])) {
		printerr(421);
		return;
	}
	f = copynum(p->ep);
	k = 0; l = p->type;
	if (k < l) {
		k++;
		if (en->next[0]->func[0] != ',' || en->next[0]->next[0] == NULL) n = en->next[0];
		else n = en->next[0]->next[0];
		q = newnum(); q->d = 1; insertdigt(q, k, 'n');
		a = removeoutadd(copynum(n->ep));
		f = replace(f, q, a);
		delnum(a);
		delnum(q);
	}
	while (k < l) {
		k++; n = arraynext(n);
		q = newnum(); q->d = 1; insertdigt(q, k, 'n');
		a = removeoutadd(copynum(n->ep));
		f = replace(f, q, a);
		delnum(a);
		delnum(q);
	}
	resetexpn(en);
	en->ep = f;
	en->type = 1;
	calculate(en, pvl);
}
void calcarraylen(expn en, varlist vl) {
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	en->retu = intvar(lenarray(en->next[0]));
	en->type = 4;
}
var intvar(int k) {
	//k non-negative
	int i;
	var ans, one, temp;
	ans = newvar();
	one = v("1");
	for (i = 0; i < k; i++) {
		temp = plus(ans, one);
		delvar(ans);
		ans = temp;
	}
	delvar(one);
	return ans;
}
/*void nameexp(expn en, varlist* pvl) {
	varlist p;
	char str[NAME_LEN];
	if (en->type != 3) return;
	if (lennum(en->ep) > NAME_LEN) return;
	exprtostr(en->ep, str);
	strcpy(en->name, NAME_LEN, str);
	p = pvarname(str, *pvl);
	if (p == NULL || (en->pre != NULL && (en->pre->func[0] == '=' || en->pre->func[0] == ':') && en->pre->next[0] == en)) return;
	if (p->type == -1) {
		en->retu = copyvar(p->x);
		en->type = 4;
		en->prop = 1;
		return;
	}
	if (p->type > 1) {
		printerr(421);
		return;
	}
	resetexpn(en);
	en->ep = copynum(p->ep);
	en->type = 1;
	calculate(en, pvl);
	iteration_number++;
}*/
void dispvarlist(varlist vl) {
	expr f, q, a, r;
	int k;
	printf("\n- VARIABLE LIST -\n");
	while (vl != NULL) {
		printf("[type %d] ", vl->type);
		printf(vl->name);
		printf(" = ");
		if (vl->type == -1) printvar(vl->x);
		else if(vl->type ==0 )printexpr(vl->ep);
		else {
			f = copynum(vl->ep); k = 0;
			while (k <= vl->type) {
				k++;
				q = newnum(); q->d = 1; insertdigt(q, k, 'n');
				a = ex("[#  ]");
				r = a->next->next;
				r->d = k / 16 + '0';
				if (r->d > '9') r->d = r->d + 'A' - '9';
				r = r->next;
				r->d = k % 16 + '0';
				if (r->d > '9') r->d = r->d + 'A' - '9';
				f = replace(f, q, a);
				delnum(a);
				delnum(q);
			}
			printexpr(f);
			delnum(f);
		}
		putchar('\n');
		vl = vl->next;
	}
}
void alldecoration(expn en) {
	if (en->type < 3) return;
	if (en->next[0] != NULL) alldecoration(en->next[0]);
	if (en->next[1] != NULL) alldecoration(en->next[1]);
	decoration(en);
}
stc newstc() {
	return newnum();
}
digt* nextmark(digt* p) {
	if (p == NULL) return p;
	do {
		if (p->d == '[') p = opp(p);
		if (p->d == '\"') p = nextqu(p);
		p = p->next;
	} while (p != NULL && !isstcsym(p));
	return p;
}
digt* firstmark(stc st) {
	if (st == NULL || isstcsym(st)) return st;
	else return nextmark(st);
}
void calcmarkexpr(digt* p,varlist* pvl) {
	digt *s, *t, *u;
	expr ep;
	expn en;
	if (p == NULL) return;
	s = t = p;
	u = s->pre;
	while (u != NULL && !isstcsym(u) && u->d != '{' && u->d != '}') {
		if (u->d == ']') u = opp(u);
		if (u->d == '\"') u = prequ(u);
		s = u;
		u = s->pre;
	}
	if (s == t) return;
	t = t->pre;
	ep = copyexpr(s, t);
	en = newexpn();
	defineexpn(en, ep);
	calc(en, pvl);
	delexpn(en);
}
var calcmarkexprwithans(digt* p, varlist* pvl) {
	digt* s, * t, * u;
	if (p == NULL) return NULL;
	s = t = p;
	u = s->pre;
	while (u != NULL && !isstcsym(u) && u->d != '{' && u->d != '}') {
		if (u->d == ']') u = opp(u);
		if (u->d == '\"') u = prequ(u);
		s = u;
		u = s->pre;
	}
	if (s == t) return NULL;
	t = t->pre;
	return cea(copyexpr(s, t), pvl);
}
digt* nextrightba(digt* p) {
	int k = 1;
	while (p->next != NULL) {
		p = p->next;
		if (p->d == '[') p = opp(p);
		if (p->d == '\"') p = nextqu(p);
		if (p->d == '{') k++;
		if (p->d == '}') k--;
		if (k == 0) return p;
	}
	return NULL;
}
digt* preleftba(digt* p) {
	int k = 1;
	while (p->pre != NULL) {
		p = p->pre;
		if (p->d == ']') p = opp(p);
		if (p->d == '\"') p = prequ(p);
		if (p->d == '}') k++;
		if (p->d == '{') k--;
		if (k == 0) return p;
	}
	return NULL;
}
digt* calcthismark(digt* p,varlist* pvl) {
	digt *q;
	int k;
	if (p == NULL || p->d == '#') return NULL;
	if (p->d == ';') {
		calcmarkexpr(p, pvl);
		return nextmark(p);
	}
	if (p->d == '$') {
		q = preleftba(p);
		if (q == NULL) return firstmark(bottomnum(p));
		else return nextmark(q);
	}
	if (p->d == '`') {
		system("pause");
		return nextmark(p);
	}
	if (p->d == '~') {
		k = 0;
		while (p->next != NULL) {
			p = p->next;
			if (p->d == '[') p = opp(p);
			if (p->d == '\"') p = nextqu(p);
			if (p->d == '{') k++;
			if (p->d == '}') k--;
			if (k <= 0 && p->d == '$') break;
		}
		return nextmark(p);
	}
	if (p->d == '\\') {
		if (!istrue(calcmarkexprwithans(p, pvl)) && p->next != NULL) {
			if (p->next->d == '{') p = opp(p->next);
			else p = nextmark(p);
		}
		return nextmark(p);
	}
}
int calcstc(stc st, varlist* pvl) {
	expr ep;
	expn en;
	digt* p;
	if(st == NULL){
		printerr(401);
		return 0;
	}
	if (!oppcheckoutba(st)) return 0;
	p = firstmark(st);
	if (p == NULL) {
		ep = copynum(st);
		en = newexpn();
		defineexpn(en, ep);
		calc(en, pvl);
		delexpn(en);
		return 1;
	}
	while (p != NULL) p = calcthismark(p, pvl);
	return 0;
}
int isstcsym(digt* p) {
	return p->d == ';' || p->d == '#' || p->d == '$' || p->d == '`' || p->d == '\\' || p->d == '~';
}
void printans(varlist vl) {
	varlist ans;
	ans = pvarname("ans", vl);
	if (ans != NULL) {
		if (ans->type == -1) printvar(ans->x);
		else printexpr(ans->ep);
		putchar('\n');
	}
}
void save(expr ep, char* fn) {
	digt* p = ep;
	FILE *fp;
	if (ep == NULL) {
		printerr(601);
		return;
	}
	if(fopen_s(&fp, fn, "a")){
		printerr(602);
		return;
	}
	while (p != NULL) {
		fputc(p->d, fp);
		p = p->next;
	}
	fclose(fp);
}
expr open(char* fn) {
	char c;
	digt* p;
	FILE *fp = NULL;
	expr ep;
	if (fopen_s(&fp, fn, "r")) {
		printerr(603);
		return NULL;
	}
	while ((c = fgetc(fp)) != EOF && (c == '\n' || c == '\t' || c == '\r' || c == '\v'));
	if (c == EOF) {
		fclose(fp);
		return NULL;
	}
	ep = newnum();
	p = ep;
	p->d = c;
	while ((c=fgetc(fp))!= EOF) {
		if (c == '\n' || c == '\t' || c == '\r' || c == '\v') continue;
		p = calldigt(p, c, 'n');
	}
	fclose(fp);
	return ep;
}
void readhead(varlist* pvl) {
	char c;
	digt* p;
	FILE *fp = NULL;
	expr ep;
	if (fopen_s(&fp, "_head", "r")) return;
	while ((c = fgetc(fp)) != EOF && (c == '\n' || c == '\t' || c == '\r' || c == '\v'));
	if (c == EOF) {
		fclose(fp);
		return;
	}
	ep = newnum();
	p = ep;
	p->d = c;
	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n' || c == '\t' || c == '\r' || c == '\v') continue;
		p = calldigt(p, c, 'n');
	}
	fclose(fp);
#ifdef COLOR_IO
	printf(COLOR_OUTPUT);
#endif
	calcstc(ep, pvl);
	delnum(ep);
}
expr getline() {
	char c;
	digt* p;
	expr ep;
	c = getchar();
	if (c == '\n') return NULL;
	ep = newnum();
	p = ep;
	p->d = c;
	while ((c = getchar()) != '\n') p = calldigt(p, c, 'n');
	return ep;
}
void printerr(int code) {
	int c, d, abscode;
	abscode = code >= 0 ? code : -code;
	c = abscode / 100;
	d = abscode - 100 * c;
#ifdef COLOR_ERRIO
	printf(COLOR_ERROR);
#endif
#define errp(X) fprintf(stderr,X)
	switch (c) {
	case 0: errp("Math"); break;
	case 1: errp("Number"); break;
	case 2: errp("Variable"); break;
	case 3: errp("Varlist"); break;
	case 4: errp("Expression"); break;
	case 5: errp("Sentence"); break;
	case 6: errp("File"); break;
	case 7: errp("CAS"); break;
	default: errp("Unknown"); break;
	}
	if (code > 0) fprintf(stderr, " Error (Code %d)", code);
	else fprintf(stderr, " Warning (Code %d)", code);
	if (d == 0) errp(":Malloc failed.");
	switch (code) {
	case 1: errp(": /0 undefined.(function divdnum)"); break;
	case 2: errp(": /0 undefined.(function adivdnum)"); break;
	case 3: errp(": /0 undefined.(function remain)"); break;
	case 4: errp(": /0 undefined.(function adivd)"); break;
	case 5: errp(":Incorrect input in function sqrt_real."); break;
	case 6: errp(":Incorrect input in function ln_real."); break;
	case 7:errp(":Illegal variable name."); break;
	case 8:errp(":The first parameter cannot be larger than the second one."); break;
	case 9: errp(":Incorrect input in function arctan_real."); break;
	case 10:errp(":Incorrect input in function strcopy."); break;
	case 11:errp(":The second parameter must be a variable name."); break;
	case 12: errp(":Incorrect input in function arcsin_real."); break;
	case 13: errp(":Incorrect input in function arccos_real."); break;
	case 101: errp(":Illegal char for a number."); break;
	case 102: errp(":Too many '.'s for a number."); break;
	case 301: errp(":Conflicting names."); break;
	case 302: errp(":Null list."); break;
	case 303: errp(":Undefined variable."); break;
	case 401: errp(":Void expression."); break;
	case 402: errp(":The expression type is not 'new expn'."); break;
	case 403: errp(":Illegal character."); break;
	case 404: errp(":The expression type is not 'defined-only'."); break;
	case 405: errp(":'(' is inconsistent with ')'."); break;
	case 406: errp(":'[' is inconsistent with ']'."); break;
	case 407: errp(":The expression type is not 'initialized'."); break;
	case 408: errp(":Variable names cannot start from a number."); break;
	case 409: errp(":The variable name is too long."); break;
	case 410: errp(":Illegal variable name."); break;
	case 411: errp(":Function names cannot start from a number."); break;
	case 412: errp(":The function name is too long."); break;
	case 413: errp(":Illegal function name."); break;
	case 414: errp(":Need operators."); break;
	case 415: errp(":Need parameters."); break;
	case 416: errp(":Variable 'acu' does not exist."); break;
	case 417: errp(":Cannot calculate an undefined expression."); break;
	case 418: errp(":Logicalizing failed."); break;
	case 419: errp(":Incorrect use of operators."); break;
	case 420: errp(":Infinite loop."); break;
	case 421: errp(":Need parameters."); break;
	case 422: errp(":'{' is inconsistent with '}'."); break;
	case 423: errp(":Need '\"'."); break;
	case 424: errp(":Maximum number of variables exceed."); break;
	case 425: errp(":Incorrect number of variables."); break;
	case 426: errp(":The cycle number must be a positive integer."); break;
	case 601: errp(":Void expression."); break;
	case 602: errp(":Cannot save the file."); break;
	case 603: errp(":Cannot run the file."); break;
	case 604: errp(":Cannot open the file."); break;
	case 701: errp(":/0 undefined."); break;
	case 702: errp(":Repeat calculating function casplus."); break;
	case 703: errp(":Repeat calculating function casprod."); break;
	case 704: errp(":Variable 'acu' does not exist. Using the default value."); break;
	case 705: errp(":Derivative error."); break;
	case -401: errp(":Nothing between '(' and ')', asuming zero."); break;
	}
#undef errp
#ifdef COLOR_ERRIO
	printf("\n"COLOR_OUTPUT);
#else
	putchar('\n');
#endif
}
int getyesornot() {
	int ans;
	expr enter;
#ifdef COLOR_IO
	printf(COLOR_INPUT);
#endif
	enter = getline();
	if (enter != NULL && (enter->d == 'y' || enter->d == 'Y' || enter->d == 'T' || enter->d == 't' || enter->d == '1')) ans = 1;
	else ans = 0;
	delnum(enter);
#ifdef COLOR_IO
	printf(COLOR_OUTPUT);
#endif
	return ans;
}
item newitem() {
	item it = (item)malloc(sizeof(struct expnset));
	if (it == NULL) {
		printerr(400);
		system("pause");
		exit(0);
	}
	it->en = NULL;
	it->next = NULL;
	it->pre = NULL;
	it->ip = NULL;
	it->coeff = NULL;
	return it;
}
item newitemset() {
	item it = (item)malloc(sizeof(struct expnset));
	if (it == NULL) {
		printerr(400);
		system("pause");
		exit(0);
	}
	it->en = NULL;
	it->next = NULL;
	it->pre = NULL;
	it->ip = NULL;
	it->coeff = v("0");
	return it;
}
item newproditemset() {
	item it = (item)malloc(sizeof(struct expnset));
	if (it == NULL) {
		printerr(400);
		system("pause");
		exit(0);
	}
	it->en = NULL;
	it->next = NULL;
	it->pre = NULL;
	it->ip = NULL;
	it->coeff = v("1");
	return it;
}
item insertitem(item p, expn en, var coeff) {
	item it = (item)malloc(sizeof(struct expnset));
	if (it == NULL) {
		printerr(400);
		system("pause");
		exit(0);
	}
	it->en = en;
	it->coeff = coeff;
	it->next = p->next;
	if (p->next != NULL) p->next->pre = it;
	it->pre = p;
	p->next = it;
	it->ip = NULL;
	return it;
}
item bottomitem(item it) {
	while (it->pre != NULL) it = it->pre;
	return it;
}
item topitem(item it) {
	while (it->next != NULL) it = it->next;
	return it;
}
void delitemset(item n) {
	item p, q;
	if (n == NULL) return;
	p = n->next;
	while (p != NULL) {
		if (p->ip != NULL) delitemset(p->ip);
		if (p->en != NULL && p->en->pre == NULL) delexpn(p->en);
		if (p->ip == NULL) delvar(p->coeff);
		q = p->next;
		free(p);
		p = q;
	}
	p = n->pre;
	while (p != NULL) {
		if (p->ip != NULL) delitemset(p->ip);
		if (p->en != NULL && p->en->pre == NULL) delexpn(p->en);
		if (p->ip == NULL) delvar(p->coeff);
		q = p->pre;
		free(p);
		p = q;
	}
	if (n->ip != NULL) delitemset(n->ip);
	if (n->en != NULL && n->en->pre == NULL) delexpn(n->en);
	if (n->ip == NULL) delvar(n->coeff);
	free(n);
}
item delitem(item p, char mode) {
	item q = NULL;
	if (p == NULL) return NULL;
	if (mode == 'p') q = p->pre;
	if (mode == 'n') q = p->next;
	if (p->next != NULL) p->next->pre = p->pre;
	if (p->pre != NULL) p->pre->next = p->next;
	if (p->ip != NULL) delitemset(p->ip);
	if (p->ip == NULL) delvar(p->coeff);
	free(p);
	return q;
}
void addtoitemset(item n, expn en, var coeff, char mode) {
	item p;
	var c;
	if (n == NULL) return;
	if (en == NULL) {
		c = plus(coeff, n->coeff);
		delvar(n->coeff);
		delvar(coeff);
		n->coeff = c;
		return;
	}
	if (en->type == 4) {
		if (mode == '+') c = plus(n->coeff, en->retu);
		else c = plus(n->coeff, op(en->retu));
		op(en->retu);
		delvar(n->coeff);
		delvar(coeff);
		n->coeff = c;
		return;
	}
	if (mode == '-') op(coeff);
	p = n;
	while (p->next != NULL) {
		p = p->next;
		if (issameclass(p->en, en)) {
			c = plus(p->coeff, coeff);
			if (iszero(c)) {
				delitem(p, 0); 
				delvar(c); delvar(coeff);
			}
			else { 
				delvar(p->coeff); p->coeff = c;
				delvar(coeff);
			}
			return;
		}
	}
	insertitem(p, en, coeff);
}
int issameclass(expn a, expn b) {
	if (a == NULL || b == NULL) return 0;
	if (a->ip == NULL && b->ip == NULL) return compexpr_sans(a->ep, b->ep);
	else if (a->ip != NULL && b->ip == NULL) {
		if (a->ip->next != NULL && a->ip->next->next == NULL && isone(a->ip->next->coeff) && compexpr_sans(a->ip->next->en->ep, b->ep)) return 1;
		else return 0;
	}
	else if (b->ip != NULL && a->ip == NULL) {
		if (b->ip->next != NULL && b->ip->next->next == NULL && isone(b->ip->next->coeff) && compexpr_sans(b->ip->next->en->ep, a->ep)) return 1;
		else return 0;
	}
	else return isitemsameclass(a->ip, b->ip);
}
void casplus(expn en, varlist vl) {
	if (en->next[0] == NULL) {
		printerr(415);
		return;
	}
	if (en->next[1] == NULL) {
		if (en->next[0]->type == 4) {
			if (en->func[0] == '+') fcalcd(plus, en, vl);
			if (en->func[0] == '-') fcalcd(minus, en, vl);
		}
		else if (en->next[0]->type > 2) casplussingle(en);
	}
	else {
		if (en->next[0]->type == 4 && en->next[1]->type == 4) {
			if (en->func[0] == '+') fcalcd(plus, en, vl);
			if (en->func[0] == '-') fcalcd(minus, en, vl);
		}
		else if (en->next[0]->type > 2 && en->next[1]->type > 2) casplusdouble(en);
	}
}
void casplussingle(expn en) {
	item n;
	if (en->it != NULL) {
		printerr(702);
		return;
	}
	if (en->next[0]->it == NULL) {
		n = newitemset();
		if (en->func[0] == '+') firstaddtoitemset(n, en->next[0], '+');
		else firstaddtoitemset(n, en->next[0], '-');
		en->it = n;
	}
	else {
		en->it = en->next[0]->it;
		en->next[0]->it = NULL;
		if (en->func[0] == '-') {
			n = en->it;
			while (n != NULL) {
				op(n->coeff);
				if (n->ip != NULL) op(n->ip->coeff);
				n = n->next;
			}
		}
	}
	en->type = 5;
	if (en->pre == NULL || (en->pre->func[0] != '+' && en->pre->func[0] != '-')) {
		delnum(en->ep); en->ep = expitemset(en->it);
		en->prop = propitem(en->it);
	}
}
void casplusdouble(expn en) {
	item n, p, q;
	int r, s;
	if (en->it != NULL) {
		printerr(702);
		return;
	}
	if (en->next[0]->it == NULL && en->next[1]->it == NULL) {
		n = newitemset();
		firstaddtoitemset(n, en->next[0], '+');
		if (en->func[0] == '+') firstaddtoitemset(n, en->next[1], '+');
		else firstaddtoitemset(n, en->next[1], '-');
		en->it = n;
	}
	else if ((en->next[0]->it != NULL && en->next[1]->it == NULL)||( en->next[0]->it == NULL && en->next[1]->it != NULL)) {
		if (en->next[0]->it != NULL) { r = 0; s = 1; }
		else { r = 1; s = 0; }
		n = en->next[r]->it;
		if (en->func[0] == '+') firstaddtoitemset(n, en->next[s], '+');
		else {
			if (s == 1) firstaddtoitemset(n, en->next[s], '-');
			else {
				p = n;
				while (p != NULL) {
					op(p->coeff);
					if (p->ip != NULL) op(p->ip->coeff);
					p = p->next;
				}
				firstaddtoitemset(n, en->next[s], '+');
			}
		}
		en->next[r]->it = NULL;
		en->it = n;
	}
	else if (en->next[0]->it != NULL && en->next[1]->it != NULL) {
		if (en->next[0]->it == en->next[1]->it) {
			printerr(702);
			return;
		}
		n = en->next[0]->it; p = en->next[1]->it;
		if (en->func[0] == '+') {
			additemtoitemset(n, p);
			q = p;
			p = p->next;
			free(q);
			while (p != NULL) {
				additemtoitemset(n, p);
				q = p;
				p = p->next;
				free(q);
			}
		}
		else {
			op(p->coeff);
			if (p->ip != NULL) op(p->ip->coeff);
			additemtoitemset(n, p);
			q = p;
			p = p->next;
			free(q);
			while (p != NULL) {
				op(p->coeff);
				if (p->ip != NULL) op(p->ip->coeff);
				additemtoitemset(n, p);
				q = p;
				p = p->next;
				free(q);
			}
		}
		en->it = n;
		en->next[0]->it = NULL;
		en->next[1]->it = NULL;
	}
	en->type = 5;
	if (en->pre == NULL || (en->pre->func[0] != '+' && en->pre->func[0] != '-')) {
		delnum(en->ep); en->ep = expitemset(en->it); 
		en->prop = propitem(en->it);
		if (en->it->next == NULL) {
			en->retu = en->it->coeff;
			en->it->coeff = NULL;
			delitemset(en->it);
			en->it = NULL;
			en->type = 4;
		}
	}
}
expr expitemset(item n) {
	expr ep = NULL, eq, q = NULL, num, exp;
	item p;
	p = n->next;
	if (p != NULL) {
		ep = expvarforexpitemset(p->coeff, 1, 1);
		if (p->en == NULL) {
			expproditemset(p->ip, &num, &exp);
			delnum(num);
			q = exp;
		}
		else if(p->en->ip==NULL) q = copynum(p->en->ep);
		else {
			expproditemset(p->en->ip, &num, &exp);
			delnum(num);
			q = exp;
		}
		if (ep == NULL) ep = q;
		else { q->pre = topnum(ep); q->pre->next = q; }
		q = topnum(q);
		p = p->next;
	}
	while (p != NULL) {
		eq = expvarforexpitemset(p->coeff, 1, 0);
		q->next = eq; eq->pre = q;
		q = topnum(q);
		if (p->en == NULL) {
			expproditemset(p->ip, &num, &exp);
			delnum(num);
			eq = exp;
		}
		else if (p->en->ip == NULL) eq = copynum(p->en->ep);
		else {
			expproditemset(p->en->ip, &num, &exp);
			delnum(num);
			eq = exp;
		}
		q->next = eq; eq->pre = q;
		q = topnum(q);
		p = p->next;
	}
	if (ep == NULL) {
		eq = expvarforexpitemset(n->coeff, 0, 1);
		if (eq == NULL) return ex("0");
	}
	else {
		eq = expvarforexpitemset(n->coeff, 0, 0);
		q->next = eq; if (eq != NULL) eq->pre = q;
		return ep;
	}
}
expr expvarforexpitemset(var x, char item, char head) {
	expr ep, t;
	number one, zero;
	digt* p;
	int r, i, ur, ui;
	if (x == NULL) return NULL;
	one = num("1"); zero = newnum();
	r = compnum(x->re, zero);
	i = compnum(x->im, zero);
	if (compnum(x->re, one)) ur = 0; else ur = 1;
	if (compnum(x->im, one)) ui = 0; else ui = 1;
	if ((item && ur && !i && x->sgr == 1 && head) || (!item && !r && !i)) {
		delnum(one); delnum(zero); return NULL; 
	}
	ep = newexpr(); p = ep;
	if (item && r && i) {
		if(!head) p = calldigt(p, '+', 'n');
		p = calldigt(p, '(', 'n');
	}
	if (r) {
		if (x->sgr == -1) p = calldigt(p, '-', 'n');
		if (x->sgr == 1 && !((item && r && i) || head)) p = calldigt(p, '+', 'n');
		if (!(item && ur && !i)) {
			t = expnum(x->re);
			p->next = t;
			t->pre = p;
			p = topnum(p);
		}
	}
	if (i) {
		if (x->sgi == -1) p = calldigt(p, '-', 'n');
		if (x->sgi == 1 &&!(head&&!r)) p = calldigt(p, '+', 'n');
		if (!ui) {
			t = expnum(x->im);
			p->next = t;
			t->pre = p;
			p = topnum(p);
		}
		p = calldigt(p, 'i', 'n');
	}
	if (r == 0 && i == 0) p = calldigt(p, '0', 'n');
	if (item && r && i) p = calldigt(p, ')', 'n');
	if(item&&!(ur&&!i)) p = calldigt(p, '*', 'n');
	ep = deldigt(ep, 'n');
	delnum(one);
	delnum(zero);
	return ep;
}
void firstaddtoitemset(item n, expn en, char sgn) {
	item p;
	if (en->ip != NULL) {
		//BUG a+0*b
		if (iszero(en->ip->coeff)) return;
		//END BUG
		p = newitem();
		p->ip = copyitemset(en->ip);
		p->coeff = copyvar(en->ip->coeff);
		if (sgn == '-') {
			op(p->coeff);
			op(p->ip->coeff);
		}
		additemtoitemset(n, p);
		free(p);
	}
	else if (en->type==4) addtoitemset(n, en, v("1"), sgn);
	else{
		p = newitem();
		p->en = en;
		if (sgn == '-') p->coeff = v("-1");
		else p->coeff = v("1");
		additemtoitemset(n, p);
		free(p);
	}
}
void casprod(expn en, varlist* pvl) {
	var vacu;
	int acu;
	if (en->next[0] == NULL || en->next[1] == NULL) {
		printerr(415);
		return;
	}
	if (en->next[0]->type == 4 && en->next[1]->type == 4) {
		if (en->func[0] == '*') fcalcd(mult, en, *pvl);
		if (en->func[0] == '/') afcalcdop(adivd, en, *pvl);
		return;
	}
	//Define Symbol df/dx
	if (isdfdx(en, *pvl)) {
		calcdfdx(en, pvl);
		return;
	}
	//End of define
	if (en->next[0]->type > 2 && en->next[1]->type > 2) {
		vacu = varname("acu", *pvl);
		if (vacu == NULL) {
			//printerr(704);
			acu = 20;
		}
		else acu = vartoint(vacu);
		casproduct(en, pvl, acu);
	}
}
void casproduct(expn en, varlist* pvl, int acu) {
	item n, p, q, u;
	int r, s;
	expr t, num, exp;
	var c;
	if (en->ip != NULL) {
		printerr(703);
		return;
	}
	if (en->next[0]->it != NULL && en->next[1]->it != NULL) {
		if (en->func[0] == '*') {
			n = newitemset();
			p = en->next[1]->it;
			while (p != NULL) {
				q = copyitemset(en->next[0]->it);
				casproplussingle(q, p, pvl);
				while (q != NULL) {
					additemtoitemset(n, q);
					u = q;
					q = q->next;
					free(u);
				}
				p = p->next;
			}
			en->it = n;
		}
		else {
			n = newproditemset();
			if (firstaddtoproditemset(n, en->next[0], '*', acu, pvl)) { printerr(701); return; }
			if (firstaddtoproditemset(n, en->next[1], '/', acu, pvl)) { printerr(701); return; }
			en->ip = n;
		}
		if (en->it != NULL) {
			en->type = 5;
			if (en->pre == NULL || (en->pre->func[0] != '+' && en->pre->func[0] != '-')) {
				delnum(en->ep); en->ep = expitemset(en->it);
				en->prop = propitem(en->it);
				if (en->it->next == NULL) {
					en->retu = en->it->coeff;
					en->it->coeff = NULL;
					delitemset(en->it);
					en->it = NULL;
					en->type = 4;
				}
			}
			return;
		}
	}
	else if ((en->next[0]->it != NULL && en->next[1]->it == NULL) || (en->next[0]->it == NULL && en->next[1]->it != NULL)) {
		if (en->next[0]->it == NULL) { r = 1; s = 0; }
		else { r = 0; s = 1; }
		if (en->next[s]->type == 4) {
			if (en->func[0] == '*') {
				casproplussimple(en->next[r]->it, en->next[s]->retu, '*', acu);
				en->it = en->next[r]->it;
				en->next[r]->it = NULL;
			}
			else {
				if (s) {
					casproplussimple(en->next[r]->it, en->next[s]->retu, '/', acu);
					en->it = en->next[r]->it;
					en->next[r]->it = NULL;
				}
				else {
					n = newproditemset();
					firstaddtoproditemset(n, en->next[0], '*', acu, pvl);
					if (firstaddtoproditemset(n, en->next[1], '/', acu, pvl)) { printerr(701); return; }
					en->ip = n;
				}
			}
		}
		else {
			if (en->next[s]->ip == NULL) {
				if (en->func[0] == '*') {
					casproplusep(en->next[r]->it, en->next[s], NULL, '*', acu, pvl);
					en->it = en->next[r]->it;
					en->next[r]->it = NULL;
				}
				else if (s == 1) {
					casproplusep(en->next[r]->it, en->next[s], NULL,  '/', acu, pvl);
					en->it = en->next[r]->it;
					en->next[r]->it = NULL;
				}
				else {
					n = newproditemset();
					if (firstaddtoproditemset(n, en->next[0], '*', acu, pvl)) { printerr(701); return; }
					if (firstaddtoproditemset(n, en->next[1], '/', acu, pvl)) { printerr(701); return; }
					en->ip = n;
				}
			}
			else {
				if (en->func[0] == '*') {
					casproplusip(en->next[r]->it, en->next[s]->ip, '*', acu, pvl);
					en->it = en->next[r]->it;
					en->next[r]->it = NULL;
				}
				else if (s == 1) {
					if (casproplusip(en->next[r]->it, en->next[s]->ip, '/', acu, pvl)) { printerr(701); return; }
					en->it = en->next[r]->it;
					en->next[r]->it = NULL;
				}
				else {
					if (firstaddtoproditemset(en->next[s]->ip, en->next[r], '/', acu, pvl)) { printerr(701); return; }
					en->ip = en->next[s]->ip;
					en->next[s]->ip = NULL;
				}
			}
		}
		if (en->it != NULL) {
			en->type = 5;
			if (en->pre == NULL || (en->pre->func[0] != '+' && en->pre->func[0] != '-')) {
				delnum(en->ep); en->ep = expitemset(en->it);
				en->prop = propitem(en->it);
				if (en->it->next == NULL) {
					en->retu = en->it->coeff;
					en->it->coeff = NULL;
					delitemset(en->it);
					en->it = NULL;
					en->type = 4;
				}
			}
			return;
		}
	}
	else if (en->next[0]->ip == NULL && en->next[1]->ip == NULL) {
		n = newproditemset();
		if (firstaddtoproditemset(n, en->next[0], '*', acu, pvl)) { printerr(701); return; }
		if (en->func[0] == '*') { if (firstaddtoproditemset(n, en->next[1], '*', acu, pvl)) { printerr(701); return; } }
		else if(firstaddtoproditemset(n, en->next[1], '/', acu, pvl)) { printerr(701); return; }
		en->ip = n;
	}
	else if ((en->next[0]->ip != NULL && en->next[1]->ip == NULL) || (en->next[0]->ip == NULL && en->next[1]->ip != NULL)) {
		if (en->next[0]->ip != NULL) { r = 0; s = 1; }
		else { r = 1; s = 0; }
		n = en->next[r]->ip;
		if (en->func[0] == '*') { 
			if (firstaddtoproditemset(n, en->next[s], '*', acu, pvl)) { printerr(701); return; }
		}
		else {
			if (s == 1) { if (firstaddtoproditemset(n, en->next[s], '/', acu, pvl)) { printerr(701); return; } }
			else {
				p = n;
				while ((p = p->next) != NULL) op(p->coeff);
				if(firstaddtoproditemset(n, en->next[s], '*', acu, pvl)) { printerr(701); return; }
			}
		}
		en->next[r]->ip = NULL;
		en->ip = n;
	}
	else if (en->next[0]->ip != NULL && en->next[1]->ip != NULL) {
		if (en->next[0]->ip == en->next[1]->ip) {
			printerr(703);
			return;
		}
		n = en->next[0]->ip; p = en->next[1]->ip;
		if (en->func[0] == '*') {
			c = mult(n->coeff, p->coeff);
			delvar(n->coeff);
			delvar(p->coeff);
			n->coeff = c;
			q = p;
			p = p->next;
			free(q);
			while (p != NULL) {
				if(addtoproditemset(n, p->en, p->coeff, '*', acu, pvl)) { printerr(701); return; }
				q = p;
				p = p->next;
				free(q);
			}
		}
		else {
			c = adivd(n->coeff, p->coeff, acu);
			if (c == NULL) return;
			delvar(n->coeff);
			delvar(p->coeff);
			n->coeff = c;
			q = p;
			p = p->next;
			free(q);
			while (p != NULL) {
				if(addtoproditemset(n, p->en, p->coeff, '/', acu, pvl)) { printerr(701); return; }
				q = p;
				p = p->next;
				free(q);
			}
		}
		en->next[0]->ip = NULL;
		en->next[1]->ip = NULL;
		en->ip = n;
	}
	en->type = 5;
	if (en->pre == NULL || (en->pre->func[0] != '*' && en->pre->func[0] != '/')) {
		if (iszero(en->ip->coeff)) {
			en->retu = newvar();
			en->type = 4;
			return;
		}
		expproditemset(en->ip, &num, &exp);
		en->prop = propproditem(en->ip);
		if (num == NULL) {
			delnum(en->ep); en->ep = exp;
			return;
		}
		if (exp == NULL) {
			en->type = 4;
			en->retu = en->ip->coeff;
			en->ip->coeff = NULL;
			delitemset(en->ip);
			en->ip = NULL;
			delnum(num);
			return;
		}
		delnum(en->ep);
		en->ep = num;
		t = topnum(en->ep);
		t->next = exp;
		t->next->pre = t;
	}
}
int addtoproditemset(item n, expn en, var coeff, char mode, int acu, varlist* pvl) {
	item p;
	var c;
	expn cn, dn, pow, pco;
	if (n == NULL || en == NULL) return 1;
	if (en->type == 4) {
		if (iszero(en->retu)) {
			if (mode == '/') return 1;
			else {
				neutralizeitemset(n); return 0;
			}
		}
		if (mode == '*') c = mult(en->retu, n->coeff);
		else c = adivd(n->coeff, en->retu, acu);
		if (c == NULL) return 1;
		delvar(n->coeff);
		delvar(coeff);
		n->coeff = c;
		return 0;
	}
	p = n;
	while ((p = p->next) != NULL) {
		if (p->en->func[0] == '^' && p->en->next[0] != NULL && p->en->next[1] != NULL && isone(p->coeff) && issameclass(p->en->next[0], en)) {
			pco = envar(coeff);
			if (mode == '/') cn = casminus(p->en->next[1], pco, *pvl);
			else cn = casplu(p->en->next[1], pco, *pvl);
			delexpn(pco);
			if (cn->type != 4) {
				pow = enep(connect(ex("("), connect(copynum(p->en->next[0]->ep), connect(ex(")^("), connect(cn->ep, ex(")"))))), pvl);
				cn->ep = NULL;
				delexpn(cn);
				p = delitem(p, 'p');
				insertitem(p, pow, v("1"));
				return 0;
			}
			else {
				if (iszero(cn->retu)) {
					delexpn(cn);
					delitem(p, 0);
					return 0;
				}
				delvar(p->coeff);
				p->coeff = cn->retu;
				cn->retu = NULL;
				delexpn(cn);
				return 0;
			}
		}
	}
	if (en->func[0] == '^' && en->type != 4 && en->next[0] != NULL && en->next[1] != NULL) {
		p = n;
		while ((p = p->next) != NULL) {
			if (p->en->func[0] == '^' && p->en->next[0] != NULL && p->en->next[1] != NULL && isone(p->coeff) && issameclass(p->en->next[0], en->next[0])) {
				pco = envar(coeff);
				dn = caspro(pco, en->next[1], pvl);
				delexpn(pco);
				if (mode == '/') cn = casminus(p->en->next[1], dn, *pvl);
				else cn = casplu(p->en->next[1], dn, *pvl);
				delexpn(dn);
				if (cn->type != 4) {
					pow = enep(connect(ex("("), connect(copynum(en->next[0]->ep), connect(ex(")^("), connect(cn->ep, ex(")"))))), pvl);
					cn->ep = NULL;
					delexpn(cn);
					p = delitem(p, 'p');
					insertitem(p, pow, v("1"));
					return 0;
				}
				else {
					if (iszero(cn->retu)) {
						delexpn(cn);
						delitem(p, 0);
						return 0;
					}
					delvar(p->coeff);
					p->coeff = cn->retu;
					cn->retu = NULL;
					delexpn(cn);
					return 0;
				}
			}
			if (issameclass(p->en, en->next[0])) {
				pco = envar(coeff);
				dn = caspro(pco, en->next[1], pvl);
				delexpn(pco);
				pco = envar(p->coeff);
				if (mode == '/') cn = casminus(pco, dn, *pvl);
				else cn = casplu(pco, dn, *pvl);
				pco->retu = NULL;
				delexpn(pco);
				delexpn(dn);
				if (cn->type != 4) {
					pow = enep(connect(ex("("), connect(copynum(en->next[0]->ep), connect(ex(")^("), connect(cn->ep, ex(")"))))), pvl);
					cn->ep = NULL;
					delexpn(cn);
					p = delitem(p, 'p');
					insertitem(p, pow, v("1"));
					return 0;
				}
				else {
					if (iszero(cn->retu)) {
						delexpn(cn);
						delitem(p, 0);
						return 0;
					}
					delvar(p->coeff);
					p->coeff = cn->retu;
					cn->retu = NULL;
					delexpn(cn);
					return 0;
				}
			}
		}
	}
	if (mode == '/') op(coeff);
	p = n;
	while (p->next != NULL) {
		p = p->next;
		if (issameclass(p->en, en)) {
			c = plus(p->coeff, coeff);
			if (iszero(c)) {
				delitem(p, 0);
				delvar(c); delvar(coeff);
			}
			else {
				delvar(p->coeff); p->coeff = c;
				delvar(coeff);
			}
			return 0;
		}
	}
	insertitem(p, copyexpn(en), coeff);
//	insertitem(p, en, coeff);
	return 0;
}
int firstaddtoproditemset(item n, expn en, char sgn, int acu, varlist* pvl) {
	/*item p;
	expn c, pow, pco;
	p = n;
	while ((p = p->next) != NULL) {
		if (p->en->func[0] == '^' && p->en->next[0] != NULL && p->en->next[1] != NULL && isone(p->coeff) && issameclass(p->en->next[0], en)) {
			pco = envar(v("1"));
			if (sgn == '/') c = casminus(p->en->next[1], pco, *pvl);
			else c = casplu(p->en->next[1], pco, *pvl);
			delexpn(pco);
			if (c->type != 4) {
				pow = enep(connect(ex("("), connect(copynum(p->en->next[0]->ep), connect(ex(")^("), connect(c->ep, ex(")"))))), pvl);
				c->ep = NULL;
				delexpn(c);
				p = delitem(p, 'p');
				insertitem(p, pow, v("1"));
				return 0;
			}
			else {
				if (iszero(c->retu)) {
					delexpn(c);
					delitem(p, 0);
					return 0;
				}
				delvar(p->coeff);
				p->coeff = c->retu;
				c->retu = NULL;
				delexpn(c);
				return 0;
			}
		}
	}
	if (en->func[0] == '^' && en->type != 4 && en->next[0] != NULL && en->next[1] != NULL) {
		p = n;
		while ((p = p->next) != NULL) {
			if (p->en->func[0] == '^' && p->en->next[0] != NULL && p->en->next[1] != NULL&&isone(p->coeff)&&issameclass(p->en->next[0],en->next[0])) {
				if(sgn=='/') c = casminus(p->en->next[1], en->next[1], *pvl);
				else c = casplu(p->en->next[1], en->next[1], *pvl);
				if (c->type != 4) {
					pow = enep(connect(ex("("), connect(copynum(en->next[0]->ep), connect(ex(")^("), connect(c->ep, ex(")"))))), pvl);
					c->ep = NULL;
					delexpn(c);
					p = delitem(p, 'p');
					insertitem(p, pow, v("1"));
					return 0;
				}
				else {
					if (iszero(c->retu)) {
						delexpn(c);
						delitem(p, 0);
						return 0;
					}
					delvar(p->coeff);
					p->coeff = c->retu;
					c->retu = NULL;
					delexpn(c);
					return 0;
				}
			}
			if (issameclass(p->en, en->next[0])) {
				pco = envar(p->coeff);
				if (sgn == '/') c = casminus(pco, en->next[1], *pvl);
				else c = casplu(pco, en->next[1], *pvl);
				pco->retu = NULL;
				delexpn(pco);
				if (c->type != 4) {
					pow = enep(connect(ex("("), connect(copynum(en->next[0]->ep), connect(ex(")^("), connect(c->ep, ex(")"))))), pvl);
					c->ep = NULL;
					delexpn(c);
					p = delitem(p, 'p');
					insertitem(p, pow, v("1"));
					return 0;
				}
				else {
					if (iszero(c->retu)) {
						delexpn(c);
						delitem(p, 0);
						return 0;
					}
					delvar(p->coeff);
					p->coeff = c->retu;
					c->retu = NULL;
					delexpn(c);
					return 0;
				}
			}
		}
	}*/
	return addtoproditemset(n, en, v("1"), sgn, acu, pvl);
}
void expproditemset(item n, expr* num,expr*exp) {
	expr ep = NULL, eq = NULL, q = NULL;
	item p;
	p = n->next;
	while (p != NULL && p->next != NULL) {
		if (ep == NULL) {
			ep = copynum(p->en->ep);
			eq = topnum(ep);
		}
		else {
			q = copynum(p->en->ep);
			eq->next = q; q->pre = eq;
			eq = topnum(eq);
		}
		q = expvarforexpproditemset(p->coeff, 0);
		eq->next = q; q->pre = eq;
		eq = topnum(eq);
		p = p->next;
	}
	if (p != NULL) {
		if (ep == NULL) {
			ep = copynum(p->en->ep);
			eq = topnum(ep);
		}
		else {
			q = copynum(p->en->ep);
			eq->next = q; q->pre = eq;
			eq = topnum(eq);
		}
		q = expvarforexpproditemset(p->coeff, 1);
		if (q != NULL) {
			eq->next = q; q->pre = eq;
		}
		q = expvarforexpitemset(n->coeff, 1, 1);
		if (q == NULL) {
			*exp = ep;
			*num = NULL;
			return;
		}
		*exp = ep;
		*num = q;
		return;
	}
	else {
		*exp = NULL;
		*num = evar(n->coeff);
		return;
	}
}
expr expvarforexpproditemset(var x, char bottom) {
	expr ep, t;
	number one, zero;
	digt* p;
	int r, i, ur, ui;
	if (x == NULL) return NULL;
	one = num("1"); zero = newnum();
	r = compnum(x->re, zero);
	i = compnum(x->im, zero);
	if (compnum(x->re, one)) ur = 0; else ur = 1;
	if (compnum(x->im, one)) ui = 0; else ui = 1;
	if (ur && !i && x->sgr == 1 && bottom) {
		delnum(one); delnum(zero); return NULL;
	}
	ep = newexpr(); p = ep;
	if (!(ur && !i && x->sgr == 1)) p = calldigt(p, '^', 'n');
	if ((r && i) || ((x->sgr == -1) && r) || ((x->sgi == -1) & i)) p = calldigt(p, '(', 'n');
	if (r) {
		if (x->sgr == -1) p = calldigt(p, '-', 'n');
		if (!(ur && !i && x->sgr == 1)) {
			t = expnum(x->re);
			p->next = t;
			t->pre = p;
			p = topnum(p);
		}
	}
	if (i) {
		if (x->sgi == -1) p = calldigt(p, '-', 'n');
		if (x->sgi == 1 && r) p = calldigt(p, '+', 'n');
		if (!ui) {
			t = expnum(x->im);
			p->next = t;
			t->pre = p;
			p = topnum(p);
		}
		p = calldigt(p, 'i', 'n');
	}
	if(!r&&!i) p = calldigt(p, '0', 'n');
	if ((r && i) || ((x->sgr == -1) && r) || ((x->sgi == -1) & i)) p = calldigt(p, ')', 'n');
	if (!bottom) p = calldigt(p, '*', 'n');
	ep = deldigt(ep, 'n');
	delnum(one);
	delnum(zero);
	return ep;
}
void additemtoitemset(item n, item q) {
	item p;
	var c, one;
	if (q->en != NULL && q->en->ip != NULL) {
		q->ip = copyitemset(q->en->ip);
		delvar(q->coeff);
		q->coeff = q->ip->coeff;
		q->en = NULL;
	}
	if (q->en == NULL) {
		if (q->ip == NULL) {
			c = plus(q->coeff, n->coeff);
			delvar(n->coeff);
			delvar(q->coeff);
			n->coeff = c;
			return;
		}
		else {
			if (q->ip->next == NULL) {
				c = plus(q->ip->coeff, n->coeff);
				delvar(n->coeff);
				delvar(q->ip->coeff);
				n->coeff = c;
				free(q->ip);
				return;
			}
			p = n;
			while (p->next != NULL) {
				p = p->next;
				if (p->ip != NULL && isitemsameclass(p->ip, q->ip)) {
					c = plus(p->ip->coeff, q->ip->coeff);
					if (iszero(c)) {
						delitem(p, 0);
						delvar(c);
					}
					else {
						delvar(p->ip->coeff); p->coeff = p->ip->coeff = c;
					}
					delitemset(q->ip);
					return;
				}
				else if (p->en != NULL && p->en->ip != NULL && isitemsameclass(p->en->ip, q->ip)) {
					c = plus(p->en->ip->coeff, q->ip->coeff);
					if (iszero(c)) {
						delitem(p, 0);
						delvar(c);
					}
					else {
						p->ip = copyitemset(p->en->ip);
						p->en = NULL;
						delvar(p->ip->coeff); p->coeff = p->ip->coeff = c;
					}
					delitemset(q->ip);
					return;
				}
				else if (q->ip->next->next == NULL && p->ip == NULL && p->en->ip == NULL && isone(q->ip->next->coeff) && issameclass(p->en, q->ip->next->en)) {
					c = plus(p->coeff, q->ip->coeff);
					if (iszero(c)) {
						delitem(p, 0);
						delvar(c);
					}
					else {
						p->ip = newitem();
						insertitem(p->ip, p->en, v("1"));
						p->en = NULL;
						delvar(p->coeff); p->coeff = p->ip->coeff = c;
					}
					delitemset(q->ip);
					return;
				}
			}
			p = insertitem(p, NULL, NULL); p->ip = q->ip; p->coeff = p->ip->coeff;
			return;
		}
	}
	p = n;
	while (p->next != NULL) {
		p = p->next;
		if (issameclass(p->en, q->en)) {
			c = plus(p->coeff, q->coeff);
			if (iszero(c)) {
				delitem(p, 0);
				delvar(c); delvar(q->coeff);
			}
			else {
				delvar(p->coeff); p->coeff = c;
				if (p->en->ip != NULL) {
					p->ip = copyitemset(p->en->ip);
					p->en = NULL;
					delvar(p->ip->coeff);
					p->ip->coeff = c;
				}
				delvar(q->coeff);
			}
			return;
		}
		else if (p->en==NULL&&p->ip->next!=NULL&&p->ip->next->next == NULL && isone(p->ip->next->coeff) && issameclass(q->en, p->ip->next->en)) {
			c = plus(p->coeff, q->coeff);
			if (iszero(c)) {
				delitem(p, 0);
				delvar(c);
			}
			else {
				delvar(p->coeff); p->coeff = p->ip->coeff = c;
			}
			delitemset(q->ip);
			return;
		}
	}
	insertitem(p, q->en, q->coeff);
}
int isitemsameclass(item a, item b) {
	item p, q, r;
	var temp;
	p = a; q = b;
	while (p->next != NULL) {
		p = p->next;
		if (q->next == NULL) return 0;
		q = q->next;
		r = b->next;
		while (r != NULL && !compexpr_sans(p->en->ep, r->en->ep)) r = r->next;
		if (r == NULL) return 0;
		temp = minus(p->coeff, r->coeff);
		if (!iszero(temp)) {
			delvar(temp);
			return 0;
		}
		else delvar(temp);
	}
	if (q->next == NULL) return 1;
	else return 0;
}
item copyitemset(item p) {
	item n, it, q;
	if (p == NULL) return NULL;
	it = (item)malloc(sizeof(struct expnset));
	if (it == NULL) {
		printerr(400);
		system("pause");
		exit(0);
	}
	it->coeff = copyvar(p->coeff);
	it->en = NULL;
	it->ip = NULL;
	it->pre = NULL;
	n = it;
	while (p->next!=NULL){
		p = p->next;
		q = it;
		it = (item)malloc(sizeof(struct expnset));
		if (it == NULL) {
			printerr(400);
			system("pause");
			exit(0);
		}
		it->coeff = copyvar(p->coeff);
		if (p->en != NULL && p->en->pre == NULL) it->en = copyexpn(p->en);
		else it->en = p->en;
		it->ip = NULL;
		it->pre = q;
		q->next = it;
		if (p->ip != NULL) it->ip = copyitemset(p->ip);
	}
	it->next = NULL;
	return n;
}
int casproplussimple(item n, var x, char mode, int acu) {
	item p = n;
	var c;
	if (iszero(x)) {
		if (mode == '*') {
			neutralizeitemset(n);
			return 0;
		}
		else return 1;
	}
	while (p != NULL) {
		if (mode == '*') c = mult(p->coeff, x);
		else c = adivd(p->coeff, x, acu);
		delvar(p->coeff);
		p->coeff = c;
		if (p->ip != NULL) p->ip->coeff = c;
		p = p->next;
	}
	return 0;
}
void casproplussingle(item n, item p, varlist* pvl) {
	if (iszero(p->coeff)) {
		neutralizeitemset(n);
		return;
	}
	if (p->en == NULL) {
		if (p->ip == NULL) casproplussimple(n, p->coeff, '*', 0);
		else casproplusip(n, p->ip, '*', 0, pvl);
		return;
	}
	if (p->en->ip != NULL) {
		casproplusip(n, p->en->ip, '*', 0, pvl);
		return;
	}
	casproplusep(n, p->en, p->coeff, '*', 0, pvl);
}
int casproplusip(item n, item ip, char mode, int acu, varlist* pvl) {
	item q, r, t, a, b;
	var c;
	if (iszero(ip->coeff)) {
		if (mode == '*') {
			neutralizeitemset(n);
			return 0;
		}
		else return 1;
	}
	if (ip->next == NULL) return casproplussimple(n, ip->coeff, mode, acu);
	if (!iszero(n->coeff)) {
		q = insertitem(n, NULL, NULL);
		q->ip = copyitemset_id(ip);
		if (mode == '/') q->coeff = adivd(n->coeff, ip->coeff, acu);
		else  q->coeff = mult(n->coeff, ip->coeff);
		delvar(q->ip->coeff);
		q->ip->coeff = q->coeff;
		if (mode == '/') {
			t = q->ip;
			while ((t = t->next) != NULL) op(t->coeff);
		}
		delvar(n->coeff);
		n->coeff = newvar();
		q = q->next;
	}
	else q = n->next;
	while (q != NULL) {
		if (q->ip == NULL && q->en->ip == NULL) {
			r = newitem();
			q->pre->next = r;
			if (q->next != NULL) q->next->pre = r;
			r->pre = q->pre;
			r->next = q->next;
			r->ip = copyitemset_id(ip);
			if (mode == '/') c = adivd(q->coeff, r->ip->coeff, acu);
			else c = mult(q->coeff, r->ip->coeff);
			delvar(r->ip->coeff);
			r->coeff = r->ip->coeff = c;
			if (mode == '/') {
				t = r->ip;
				while ((t = t->next) != NULL) op(t->coeff);
			}
			addpluseptoproditemset(r->ip, q->en, NULL, 0, acu, pvl);
			delvar(q->coeff);
			free(q);
			q = r;
		}
		else {
			if (q->ip != NULL) a = q->ip;
			else {
				a = copyitemset(q->en->ip);
				q->en = NULL;
				q->ip = a;
				delvar(q->coeff);
			}
			b = copyitemset_id(ip);
			if (mode == '*') {
				c = mult(a->coeff, b->coeff);
				delvar(a->coeff);
				delvar(b->coeff);
				a->coeff = c;
				r = b;
				b = r->next;
				free(r);
				while (b != NULL) {
					if (addtoproditemset(a, b->en, b->coeff, '*', acu, pvl)) { printerr(701); return 1; }
					r = b;
					b = b->next;
					free(r);
				}
			}
			else {
				c = adivd(a->coeff, b->coeff, acu);
				if (c == NULL) return 1;
				delvar(a->coeff);
				delvar(b->coeff);
				a->coeff = c;
				r = b;
				b = r->next;
				free(r);
				while (b != NULL) {
					if (addtoproditemset(a, b->en, b->coeff, '/', acu, pvl))
					{ printerr(701); return 1; }
					r = b;
					b = b->next;
					free(r);
				}
			}
			q->coeff = q->ip->coeff;
		}
		q = q->next;
	}
	q = n->next;
	while (q != NULL) {
		if (q->ip != NULL && q->ip->next == NULL) {
			c = plus(n->coeff, q->ip->coeff);
			delitem(q, 0);
			delvar(n->coeff);
			n->coeff = c;
			break;
		}
		q = q->next;
	}
	return 0;
}
int casproplusep(item n, expn en, var coeff, char mode, int acu, varlist* pvl) {
	item q, r;
	var one = NULL, c;
	if (coeff == NULL) coeff = one = v("1");
	if (iszero(coeff)) {
		if (mode == '*') {
			neutralizeitemset(n);
			if(one!=NULL) delvar(one);
			return 0;
		}
		else {
			if (one != NULL) delvar(one);
			return 1;
		}
	}
	q = n->next;
	while (q != NULL) {
		if (q->ip == NULL && q->en->ip == NULL) {
			r = newitem();
			if (q->pre != NULL) q->pre->next = r;
			if (q->next != NULL) q->next->pre = r;
			r->next = q->next;
			r->pre = q->pre;
			r->ip = newitem();
			r->ip->next = q;
			r->ip->coeff = q->coeff;
			q->coeff = v("1");
			q->next = NULL;
			q->pre = r->ip;
			addpluseptoproditemset(r->ip, en, coeff, mode, acu, pvl);
			r->coeff = r->ip->coeff;
			q = r->next;
		}
		else {
			if (q->ip != NULL) addpluseptoproditemset(q->ip, en, coeff, mode, acu, pvl);
			else {
				q->ip = copyitemset(q->en->ip);
				addpluseptoproditemset(q->ip, en, coeff, mode, acu, pvl);
				q->en = NULL;
			}
			q->coeff = q->ip->coeff;
			q = q->next;
		}
	}
	if (!iszero(n->coeff)) {
		if (mode == '/') c = adivd(n->coeff, coeff, acu);
		else c = mult(n->coeff, coeff);
		addpluseptoitemset(n, en, c, mode);
		delvar(c);
		delvar(n->coeff);
		n->coeff = newvar();
	}
	q = n->next;
	while (q != NULL) {
		if (q->ip != NULL && q->ip->next == NULL) {
			c = plus(n->coeff, q->ip->coeff);
			delitem(q, 0);
			delvar(n->coeff);
			n->coeff = c;
			break;
		}
		q = q->next;
	}
	if (one != NULL) delvar(one);
	return 0;
}
void neutralizeitemset(item n){
	item p, q;
	if (n == NULL) return;
	p = n->next;
	while (p != NULL) {
		if (p->ip != NULL) delitemset(p->ip);
		q = p->next;
		delvar(p->coeff);
		free(p);
		p = q;
	}
	delvar(n->coeff);
	n->coeff = newvar();
	n->next = NULL;
	n->pre = NULL;
	n->ip = NULL;
	n->en = NULL;
}
void addpluseptoproditemset(item ip, expn en, var coeff, char mode, int acu, varlist* pvl) {
	var c;
	addtoproditemset(ip, en, v("1"), mode, acu, pvl);
	if (coeff != NULL) {
		if (mode == '/') c = adivd(ip->coeff, coeff, acu);
		else c = mult(ip->coeff, coeff);
		delvar(ip->coeff);
		ip->coeff = c;
	}
	return;
/*	item p;
	var c, un;
	p = ip;
	while (p->next != NULL) {
		p = p->next;
		if (compexpr_sans(p->en->ep, en->ep)) {
			if (mode == '/') un = v("-1");
			else un = v("1");
			c = plus(p->coeff, un);
			delvar(un);
			if (iszero(c)) {
				delitem(p, 0);
				delvar(c); 
			}
			else {
				delvar(p->coeff); p->coeff = c;
			}
			if (coeff != NULL) {
				c = mult(ip->coeff, coeff);
				delvar(ip->coeff);
				ip->coeff = c;
			}
			return;
		}
	}
	if (mode == '/') insertitem(p, en, v("-1"));
	else insertitem(p, en, v("1"));
	if (coeff != NULL) {
		if (mode == '/') c = adivd(ip->coeff, coeff, acu);
		else c = mult(ip->coeff, coeff);
		delvar(ip->coeff);
		ip->coeff = c;
	}*/
}
void addpluseptoitemset(item n, expn en, var coeff, char mode) {
	item p;
	var c;
	expr ep;
	var* pco = NULL;
	p = n;
	while (p->next != NULL) {
		p = p->next;
		ep = NULL;
		if (p->en != NULL && mode == '*') {
			ep = p->en->ep; pco = &(p->coeff);
		}
		else {
			if (mode == '/') {
				if (p->ip->next != NULL && p->ip->next->next == NULL && isnegaone(p->ip->next->coeff)) {
					ep = p->ip->next->en->ep; pco = &(p->ip->coeff);
				}
			}
			else {
				if (p->ip->next != NULL && p->ip->next->next == NULL && isone(p->ip->next->coeff)) {
					ep = p->ip->next->en->ep; pco = &(p->ip->coeff);
				}
			}
		}
		if (ep != NULL) {
			if (compexpr_sans(ep, en->ep)) {
				c = plus(*pco, coeff);
				if (iszero(c)) {
					delitem(p, 0);
					delvar(c);
				}
				else {
					delvar(*pco); *pco = c;
				}
				return;
			}
		}
	}
	if (mode == '/') {
		p = insertitem(p, NULL, NULL);
		p->ip = newitem();
		p->ip->coeff = copyvar(coeff);
		p->coeff = p->ip->coeff;
		insertitem(p->ip, en, v("-1"));
	}
	else insertitem(p, en, copyvar(coeff));
}
void casdiff(expn en, varlist* pvl) {
	expn anse;
	if (lenarray(en->next[0]) != 2) {
		printerr(425);
		return;
	}
	if (arraynext(en->next[0]->next[0])->name[0] == 0) return;
	anse = casdif(en->next[0]->next[0], arraynext(en->next[0]->next[0])->name, pvl);
	if (anse == NULL) {
		printerr(705);
		return;
	}
	replaceexpn(en, anse);
}
expn casdif(expn en, char* var, varlist* pvl) {
	expn l, r, lc, rc, la, ra, anse;
	digt* p;
	if (en == NULL || var == NULL) return NULL;
	if (en->type == 4) {
		anse = newexpn();
		anse->type = 4;
		anse->prop = 1;
		anse->ep = ex("0");
		anse->retu = v("0");
		return anse;
	}
	if (en->it != NULL) {
		anse = newexpn();
		anse->it = casdifit(en->it, var, pvl);
		if (anse->it->next == NULL) {
			anse->retu = anse->it->coeff;
			anse->it->coeff = NULL;
			delitemset(anse->it);
			anse->it = NULL;
			anse->type = 4;
			anse->prop = 1;
			return anse;
		}
		else {
			anse->ep = expitemset(anse->it);
			anse->type = 5;
			anse->prop = propitem(anse->it);
			return anse;
		}
	}
	if (en->ip != NULL) {
		anse = newexpn();
		anse->it = casdifip(en->ip, var, pvl);
		if (anse->it->next == NULL) {
			anse->retu = anse->it->coeff;
			anse->it->coeff = NULL;
			delitemset(anse->it);
			anse->it = NULL;
			anse->type = 4;
			anse->prop = 1;
			return anse;
		}
		else {
			anse->ep = expitemset(anse->it);
			anse->type = 5;
			anse->prop = propitem(anse->it);
			return anse;
		}
	}
	if (en->next[0] == NULL) {
		anse = newexpn();
		anse->type = 4;
		anse->prop = 1;
		if (isepthevar(en->ep, var)) {
			anse->ep = ex("1");
			anse->retu = v("1");
		}
		else {
			anse->ep = ex("0");
			anse->retu = v("0");
		}
		return anse;
	}
	l = casdif(en->next[0], var, pvl);
	r = casdif(en->next[1], var, pvl);
	lc = casdifunc(en, 'l', pvl);
	rc = casdifunc(en, 'r', pvl);
	la = caspro(lc, l, pvl);
	ra = caspro(rc, r, pvl);
	delexpn(l); delexpn(r); delexpn(lc); delexpn(rc);
	anse = casplu(la, ra, *pvl);
	delexpn(la); delexpn(ra);
	if (anse == NULL) {
		anse = newexpn();
		anse->ep = ex("diff(");
		p = topnum(anse->ep);
		p->next = copynum(en->ep);
		p->next->pre = p;
		p = insertdigt(topnum(p), ',', 'n');
		p->next = ex(var);
		p->next->pre = p;
		insertdigt(topnum(p), ')', 'n');
		strcpy(anse->func, NAME_LEN, "diff");
/*		anse->next[0] = copyexpn(en);
		anse->next[0]->pre = anse;
		anse->next[0]->pre_s = p->next;
		anse->next[0]->pre_e = q;*/
		anse->type = 5;
		anse->prop = 1;
	}
	return anse;
}
expn casplu(expn a, expn b, varlist vl) {
	expn en;
	if (a == NULL && b == NULL) return NULL;
	if (a == NULL) return copyexpn(b);
	if (b == NULL) return copyexpn(a);
	en = newexpn();
	en->next[0] = copyexpn(a);
	en->next[1] = copyexpn(b);
	en->ep = ex(" + ");
	if (en->next[0] != NULL) {
		en->next[0]->pre = en;
		en->next[0]->pre_s = en->ep;
		en->next[0]->pre_e = en->ep;
	}
	if (en->next[1] != NULL) {
		en->next[1]->pre = en;
		en->next[1]->pre_s = en->ep->next->next;
		en->next[1]->pre_e = en->ep->next->next;
	}
	en->func[0] = '+';
	en->func[1] = 0;
	decoration(en->next[0]);
	decoration(en->next[1]);
	casplus(en, vl);
	return en;
}
expn casminus(expn a, expn b, varlist vl) {
	expn en;
	if (a == NULL && b == NULL) return NULL;
	if (a == NULL) return copyexpn(b);
	if (b == NULL) return copyexpn(a);
	en = newexpn();
	en->next[0] = copyexpn(a);
	en->next[1] = copyexpn(b);
	en->ep = ex(" - ");
	if (en->next[0] != NULL) {
		en->next[0]->pre = en;
		en->next[0]->pre_s = en->ep;
		en->next[0]->pre_e = en->ep;
	}
	if (en->next[1] != NULL) {
		en->next[1]->pre = en;
		en->next[1]->pre_s = en->ep->next->next;
		en->next[1]->pre_e = en->ep->next->next;
	}
	en->func[0] = '-';
	en->func[1] = 0;
	decoration(en->next[0]);
	decoration(en->next[1]);
	casplus(en, vl);
	return en;
}
expn caspro(expn a, expn b, varlist* pvl) {
	expn en;
	if (a == NULL || b == NULL) return NULL;
	en = newexpn();
	en->next[0] = copyexpn(a);
	en->next[1] = copyexpn(b);
	en->ep = ex(" * ");
	if (en->next[0] != NULL) {
		en->next[0]->pre = en;
		en->next[0]->pre_s = en->ep;
		en->next[0]->pre_e = en->ep;
	}
	if (en->next[1] != NULL) {
		en->next[1]->pre = en;
		en->next[1]->pre_s = en->ep->next->next;
		en->next[1]->pre_e = en->ep->next->next;
	}
	en->func[0] = '*';
	en->func[1] = 0;
	decoration(en->next[0]);
	decoration(en->next[1]);
	casprod(en, pvl);
	return en;
}
expn casdifunc(expn en, char mode, varlist* pvl) {
	expr ep;
	if (en->func[0] == '^') {
		if(mode=='l') {
			ep = connect(ex("("), connect(copynum(en->next[1]->ep), connect(ex(")*"), connect(copynum(en->next[0]->ep), connect(ex("^(("), connect(copynum(en->next[1]->ep), ex(")-1)")))))));
			return enep(ep, pvl);
		}
		if (mode == 'r') {
			ep = connect(ex("("), connect(copynum(en->next[0]->ep), connect(ex(")^("), connect(copynum(en->next[1]->ep), connect(ex(")*ln("), connect(copynum(en->next[0]->ep), ex(")")))))));
			return enep(ep, pvl);
		}

	}
	if (mode == 'r') return NULL;
	if (strcmp(en->func, "exp") == 0) return copyexpn(en);
	if (strcmp(en->func, "ln") == 0) {
		ep = connect(ex("1/("), connect(copynum(en->next[0]->ep), ex(")")));
		return enep(ep, pvl);
	}
	if (strcmp(en->func, "sin") == 0) {
		ep = connect(ex("cos("), connect(copynum(en->next[0]->ep), ex(")")));
		return enep(ep, pvl);
	}
	if (strcmp(en->func, "cos") == 0) {
		ep = connect(ex("-sin("), connect(copynum(en->next[0]->ep), ex(")")));
		return enep(ep, pvl);
	}
	if (strcmp(en->func, "tan") == 0) {
		ep = connect(ex("cos("), connect(copynum(en->next[0]->ep), ex(")^(-2)")));
		return enep(ep, pvl);
	}
//	if (strcmp(en->func, "sqrt") == 0)
//	if (strcmp(en->func, "log") == 0)
	if (strcmp(en->func, "sinh") == 0) {
		ep = connect(ex("cosh("), connect(copynum(en->next[0]->ep), ex(")")));
		return enep(ep, pvl);
	}
	if (strcmp(en->func, "cosh") == 0) {
		ep = connect(ex("sinh("), connect(copynum(en->next[0]->ep), ex(")")));
		return enep(ep, pvl);
	}
	if (strcmp(en->func, "tanh") == 0) {
		ep = connect(ex("cosh("), connect(copynum(en->next[0]->ep), ex(")^(-2)")));
		return enep(ep, pvl);
	}
	if (strcmp(en->func, "arctan") == 0) {
		ep = connect(ex("1/(1+("), connect(copynum(en->next[0]->ep), ex(")^2)")));
		return enep(ep, pvl);
	}
	if (strcmp(en->func, "arcsin") == 0) {
		ep = connect(ex("(1-("), connect(copynum(en->next[0]->ep), ex(")^2)^(-0.5)")));
		return enep(ep, pvl);
	}
	if (strcmp(en->func, "arccos") == 0) {
		ep = connect(ex("-(1-("), connect(copynum(en->next[0]->ep), ex(")^2)^(-0.5)")));
		return enep(ep, pvl);
	}
	return NULL;
}
item casdifit(item it, char* va, varlist* pvl) {
	item p, q, r, n;
	expn dif;
	var c, d;
	p = it;
	n = newitemset();
	while ((p = p->next) != NULL) {
		if (p->en != NULL) {
			dif = casdif(p->en, va, pvl);
			if (dif->type == 4) {
				c = mult(p->coeff, dif->retu);
				d = plus(n->coeff, c);
				delvar(c);
				delvar(n->coeff);
				n->coeff = d;
				delexpn(dif);
			}
			else if (dif->it != NULL) {
				q = copyitemset_id(dif->it);
				c = mult(p->coeff, q->coeff);
				delvar(q->coeff);
				q->coeff = c;
				additemtoitemset(n, q);
				r = q;
				q = q->next;
				free(r);
				while (q != NULL) {
					c = mult(p->coeff, q->coeff);
					delvar(q->coeff);
					q->coeff = c;
					if (q->ip != NULL) q->ip->coeff = q->coeff;
					additemtoitemset(n, q);
					r = q;
					q = q->next;
					free(r);
				}
				delexpn(dif);
			}
			else if (dif->ip != NULL) {
				q = newitem();
				q->ip = copyitemset_id(dif->ip);
				q->coeff = mult(p->coeff, q->ip->coeff);
				delvar(q->ip->coeff);
				q->ip->coeff = q->coeff;
				additemtoitemset(n, q);
				free(q);
				delexpn(dif);
			}
			else {
				q = newitem();
				q->en = dif;
				q->coeff = copyvar(p->coeff);
				additemtoitemset(n, q);
				free(q);
			}
		}
		else {
			q = casdifip(p->ip, va, pvl);
			additemtoitemset(n, q);
			r = q;
			q = q->next;
			free(r);
			while (q != NULL) {
				additemtoitemset(n, q);
				r = q;
				q = q->next;
				free(r);
			}
		}
	}
	return n;
}
item casdifip(item ip, char* va, varlist* pvl) {
	item n, p, q, r, s;
	var c, one;
	expn dif;
	n = newitemset();
	p = ip;
	while ((p = p->next) != NULL) {
		dif = casdif(p->en, va, pvl);
		if (dif->type != 4 || !iszero(dif->retu)) {
			q = copyitemset_id(ip);
			s = ip->next;
			r = q->next;
			while (s != p) {
				s = s->next;
				r = r->next;
			}
			if (isone(r->coeff)) {
				delitem(r, 0);
			}
			else {
				c = mult(q->coeff, r->coeff);
				delvar(q->coeff);
				q->coeff = c;
				one = v("1");
				c = minus(r->coeff, one);
				delvar(r->coeff); delvar(one);
				r->coeff = c;
			}
			if (dif->it == NULL) {
				addtoproditemset(q, dif, v("1"), '*', 0, pvl);
				r = newitem();
				r->ip = q;
				r->coeff = q->coeff;
				additemtoitemset(n, r);
				free(r);
			}
			else {
				r = copyitemset_id(dif->it);
				casproplusip(r, q, '*', 0, pvl);
				delitemset(q);
				q = r;
				additemtoitemset(n, q);
				r = q;
				q = q->next;
				free(r);
				while (q != NULL) {
					additemtoitemset(n, q);
					r = q;
					q = q->next;
					free(r);
				}
			}
		}
		delexpn(dif);
	}
	return n;
}
int propitem(item n) {
	if (n->next == NULL) return 1;
	if (n->next->next != NULL) return 4;
	if (!iszero(n->coeff)) return 4;
	if (!isone(n->next->coeff)) return 4;
	if (n->next->ip != NULL) return propproditem(n->next->ip);
	return n->next->en->prop;
}
int propproditem(item n) {
	if (n->next == NULL) return 1;
	if (n->next->next != NULL) return 4;
	if (iszero(n->coeff)) return 1;
	if (!isone(n->coeff)) return 4;
	return n->next->en->prop;
}
int isepthevar(expr ep, char* va) {
	char str[NAME_LEN];
	if (lennum(ep) > NAME_LEN) return 0;
	exprtostr(ep, str);
	if (strcmp(str, va)) return 0;
	else return 1;
}
item copyitemset_id(item p) {
	item n, it, q;
	if (p == NULL) return NULL;
	it = (item)malloc(sizeof(struct expnset));
	if (it == NULL) {
		printerr(400);
		system("pause");
		exit(0);
	}
	it->coeff = copyvar(p->coeff);
	it->en = NULL;
	it->ip = NULL;
	it->pre = NULL;
	n = it;
	while (p->next != NULL) {
		p = p->next;
		q = it;
		it = (item)malloc(sizeof(struct expnset));
		if (it == NULL) {
			printerr(400);
			system("pause");
			exit(0);
		}
		it->coeff = copyvar(p->coeff);
		it->en = copyexpn(p->en);
		it->ip = NULL;
		it->pre = q;
		q->next = it;
		if (p->ip != NULL) it->ip = copyitemset_id(p->ip);
	}
	it->next = NULL;
	return n;
}
int compexpr_sans(expr a, expr b) {
	int c, d;
	expr e, f;
	if (a == NULL && b == NULL) return 1;
	if ((a == NULL && b != NULL) || (a != NULL && b == NULL)) return 0;
	if (c = (a->d == '(')) e = removeoutadd(copynum(a));
	else e = a;
	if (d = (b->d == '(')) f = removeoutadd(copynum(b));
	else f = b;
	while (e->next != NULL && f->next != NULL) {
		if (e->d != f->d) {
			if (c) delnum(e);
			if (d) delnum(f);
			return 0;
		}
		e = e->next; f = f->next;
	}
	if (e->d != f->d) {
		if (c) delnum(e);
		if (d) delnum(f);
		return 0;
	}
	if (!(e->next == NULL && f->next == NULL)) {
		if (c) delnum(e);
		if (d) delnum(f);
		return 0;
	}
	if (c) delnum(e);
	if (d) delnum(f);
	return 1;
}
expn caspowerint(expn en, int n, varlist* pvl) {
	int m;
	expn temp, s, t;
	if (n == 1) return copyexpn(en);
	if (n == 0) return enep(ex("1"), pvl);
	if (n % 2 == 0) {
		temp = caspowerint(en, n / 2, pvl);
		s = caspro(temp, temp, pvl);
		delexpn(temp);
		return s;
	}
	else {
		m = n - n / 2;
		temp = caspowerint(en, n / 2, pvl);
		t = caspowerint(en, m, pvl);
		s = caspro(temp, t, pvl);
		delexpn(temp);
		delexpn(t);
		return s;
	}
}
int isdfdx(expn en, varlist vl) {
	digt* p;
	varlist pv;
//	This function should only be used in the case en->next[0], en->next[1]!=NULL.
	if (en->func[0] != '/' || en->next[0]->type == 4 || en->next[1]->type == 4 || en->next[0]->ep->d != 'd' || en->next[1]->ep->d != 'd' || en->next[0]->ep->next == NULL || en->next[1]->ep->next == NULL) return 0;
	if ((!strcmp(en->next[0]->func, "d") || !strcmp(en->next[1]->func, "d")) && (pv = pvarname("d", vl)) != NULL && pv->type == 1) return 0;
	if (!strcmp(en->next[0]->func, "d")) {
		if (lenarray(en->next[0]->next[0]) != 1) return 0;
	}
	else {
		if (en->next[0]->next[0] != NULL) return 0;
		if (en->next[0]->name[0] != 0) {
			if (pvarname(en->next[0]->name, vl) != NULL) return 0;
			if (isnumber(en->next[0]->ep->next)) return 0;
		}
		else {
			if (lennum(en->next[0]->ep) > NAME_LEN + 1) return 0;
			if (!isalpha(en->next[0]->ep->next)) return 0;
			p = en->next[0]->ep->next;
			while ((p = p->next) != NULL) {
				if (!isalphanumber(p)) return 0;
			}
		}
	}
	if (!strcmp(en->next[1]->func, "d")) {
		if (lenarray(en->next[1]->next[0]) != 1) return 0;
		if (en->next[1]->next[0]->name[0] == 0) return 0;
	}
	else {
		if (en->next[1]->next[0] != NULL) return 0;
		if (en->next[1]->name[0] != 0) {
			if (pvarname(en->next[1]->name, vl) != NULL) return 0;
			if (isnumber(en->next[1]->ep->next)) return 0;
		}
		else {
			if (lennum(en->next[1]->ep) > NAME_LEN + 1) return 0;
			if (!isalpha(en->next[1]->ep->next)) return 0;
			p = en->next[1]->ep->next;
			while ((p = p->next) != NULL) {
				if (!isalphanumber(p)) return 0;
			}
		}
	}
	return 1;
}
void calcdfdx(expn en, varlist* pvl) {
	expn endif, exp;
	int dexp = 0;
	char vn[NAME_LEN];
	if (!strcmp(en->next[1]->func, "d")) strcpy(vn, NAME_LEN, en->next[1]->next[0]->name);
	else exprtostr(en->next[1]->ep = deldigt(en->next[1]->ep, 'n'), vn);
	if (!strcmp(en->next[0]->func, "d")) exp = en->next[0]->next[0];
	else {
		exp = enep(copynum(en->next[0]->ep = deldigt(en->next[0]->ep, 'n')), pvl);
		dexp = 1;
	}
	endif = casdif(exp, vn, pvl);
	if (dexp) delexpn(exp);
	if (endif == NULL) {
		printerr(705);
		return;
	}
	replaceexpn(en, endif);
}
void calcspace(expn en, varlist* pvl) {

	en->prop = 2;
}
