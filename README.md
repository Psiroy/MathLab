# MathLab
An extremely lightweight calculator and compiler based on the computer algebra system, developed by Hongquan Yang.
It is written all by myself without using existing libraries and in console C only, so it takes up very little space and is ready to use (<120KB, in a single portable executable file). This project was originally written in January 2016 during the winter break of my freshman year after just learning C programming. It has been expanded with two major functional expansions to become what it is now.

## Key Features
- CAS Scientific Calculation: Customize expression functions with up to 256 dimensions vector parameter or complex numeric variables for numerical calculations of arbitrary precision or addition, subtraction, multiplication, division, exponentiation, and derivation with any number of unknown variables or unkown expressions. Common mathematical functions, such as trigonometric functions, are built in.
- Simple programming: Real-time compilation of running code files. Customize the preset code for startup environment simply by placing the code files in the directory. Input and output functions. Embedded console command prompt. String operations and file manipulation. Nested functions or programs, local and global variables.

## Download Executable Files
**DROPBOX |** [MathLab for Windows & User's Guide](https://www.dropbox.com/sh/s0k7sffsucz3990/AADoieglSGqV1hkw2jNwtDbna?dl=0)
 (The Chinese version of the user's guide is written for version 2.7.3. The English version is for version 2.5.)

## Make your own portable executable files with MathLab
- **Step 1 |** Write and save your MathLab code to a text file.
- **Step 2 |** Copy MathLab.exe to your code text directory.
- **Step 3 |** Create a new file with the name _head (no extension) in the same directory. Edit the file _head with a plain text editor and save the following code in _head. (The code written in _head will be run when MathLab is loaded.)
```
cmd("title [YOUR_PROGRAM_TITLE]");
run([YOUR_MATHLAB_CODE_FILE_NAME]);
exit;
```
- **Step 4 |** Rename MathLab.exe to your program name if you need. Then running MathLab.exe will automatically run the program you wrote. You can package MathLab.exe, _head, and your code file as your program.

## License
This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
For commercial use, please contact me.

## Latest Update in Version 3.0.20210630
- Remove dead loop check. Now the dead loop will be stuck forever, and calculations with large exponential operations may return a wrong result.
- Found the double decimal point bug, which means two decimal points in a number will cause the program to terminate.
- New Grammar Feature: Space Operator. (developing)
- New Grammar Feature: Call function by [[String_of_function_name]]([parameters])
- New Grammar Feature: Run calculations for integer n times by [[interger_n]]([expression])
```
>a=x
x
>[9](a=a+x)
10*x
>a
10*x
>[strplus("si","n")](1)
0.8414709848078965066
>sin(1)
0.8414709848078965066
```
## Examples
**Example 0.** Output Hello World!
```
>@[Hello World!];
Hello World!
```
**Example 1.** What are the last 3 digits of 2^2017?
```
>2^2017
15048778649098708900024591334476113300977322584816945731700558880122683541322076177782007219047710981075054947716136472064126077643824238840065967471547556631560845937254371164250279660518119161387932318441601269076015902051059415639302737237176005947674459708871461936685990491668258704528004116902095445209142907238410945246315083832742911528263323025464230244084170860858180649908473861473732904002152903343524599316744998729600734613976276435145967459880414992210979426610665493516790262296298203742913223142110136307331732133567798248592543027545063446994685630981451647656652367955517092809805578371072
```
Answer: 072

**Example 2.** Define the Fibonacci sequence F(n) and calculate F(16).

*Method 1*
```
>F(n)=[n<2\{1;#}F(n-1)+F(n-2);]
[n<2\{1;#}F(n-1)+F(n-2);]
>F(16)
1597
```
*Method 2*
```
>F(0)=F(1)=1
1
>F(n)=F(n-1)+F(n-2)
F(n-1)+F(n-2)
>F(16)
1597
```
**Example 3.** For a function f on R^4 Euclidean space, define grad f=(∂f/∂x,∂f/∂y,∂f/∂z,∂f/∂w). For a vector v=(x,y,z,w)∈R^4, define R(v)=(y,-x,w,-z). Calculate R(grad f) when f(x,y,z,w)=x*z+y*w.
```
>grad(f)=[d(f)/dx,d(f)/dy,d(f)/dz,d(f)/dw];
>R(x,y,z,w)=(y,-x,w,-z);
>f=x*z+y*w;
>v=+grad(f)
z,w,x,y
>R(v)
w,-z,y,-x
```
**Example 4.** Define a function to decide whether a positive integer is a prime number or not. Is 2017 a prime number?
```
>isprime(n_)=[>n=n_;n<3\{n-1;#}n%2?0\{0;#}p=1;s=sqrt(n);{p=p+2;p>s\~n%p?0\{0;#}$}1;]
[>n=n_;n<3\{n-1;#}n%2?0\{0;#}p=1;s=sqrt(n);{p=p+2;p>s\~n%p?0\{0;#}$}1;]
>isprime(2017)
1
```
**Example 5.** Define the exterior derivative operator d in the homogeneous space of Λ R^3. Compute d(x*z+e^sin(y)*z+ln(x)*y), d(x*e^y*z^2*(dy+dz)) and d(1/z*dxΛdy).
```
>d(f)=[>_temp=(d(d(f)/ddxdy)/dz+d(d(f)/ddydz)/dx+d(d(f)/ddzdx)/dy)*dxdydz;_temp?0\_temp=(d(d(f)/ddy)/dx-d(d(f)/ddx)/dy)*dxdy+(d(d(f)/ddz)/dy-d(d(f)/ddy)/dz)*dydz+(d(d(f)/ddx)/dz-d(d(f)/ddz)/dx)*dzdx;_temp?0\_temp=d(f)/dx*dx+d(f)/dy*dy+d(f)/dz*dz;_temp;]; 
>d(x*z+e^sin(y)*z+ln(x)*y)
z*dx+y*x^(-1)*dx+e^sin(y)*cos(y)*z*dy+ln(x)*dy+x*dz+e^sin(y)*dz
>d(x*e^y*z^2*(dy+dz))
e^y*z^2*dxdy+e^y*x*z^2*dydz+2*x*e^y*z*dydz+e^y*z^2*dzdx
>d(1/z*dxdy)
-z^(-2)*dxdydz
```
**Example 6.** Create an executable file to decompose the prime factors of positive integers.

*File _head:*
```
cmd("title Prime Factor");
run(factor.txt);
exit;
```
*File factor.txt:*
```
:n;
p=2;q=0;f=0;
sq=floor(sqrt(n));
{
if=n%p?0\{
	q?0\{
	f>0\2@[*];
	f=1;2@p;
	}
n=n/p;q=q+1;
}
!if\{
p=p+2;p?4\p=3;
q>1\{2@[^];2@q;}q=0;
}
p>sq\p=n;
n?1\~
$}
q>1\{2@[^];2@q;}
@[ ];`
```
Execution Results (Enter 2352 to verify)
```
n=2352
2^4*3*7^2
Press any key to continue...
```
