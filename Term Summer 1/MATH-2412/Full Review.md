# Summary
- __Polar Form__ - $r(\cos \theta+i\sin \theta)$
- __Rectangular Form__ - $a+bi$
- [[Sum & Difference Formulas]]
- [[Half-Angle Formulas]]
- [[Double Angle Formulas]]
- [[the-quadratic-formula-and-the-values-of-discriminant.webp]]
- __DeMoivre's Theorem__ - $[r(\cos \theta+i\sin \theta)]^n=r^n(\cos \theta*n+i\sin \theta*n)$
- __Powers Theorem__ - $^n\sqrt{ z }=^n\sqrt{ r }\left[ \cos\left( \frac{\theta+2\pi k}{n}+i\sin\left( \frac{\theta+2\pi k}{n} \right) \right) \right]$
- __Arithmetic sequence__ = $a_{n}=a_{1}+(n-1)d$
- __Series Formula__ = $S_{n}=\frac{n}{2}[a_{1}+a_{n}]$
- __General Term__ = $a_{n}=a_{1}r^{n-1}$
- __Sum of Series of n__ = $S_{n}=\frac{a_{1}(1-r^n)}{1-r}$
- __Binomial Coefficient__ - $\binom{n}{r}=\frac{n!}{r!(n-r)!}$
- __Binomial Theorem__ - $(a+b)^n=\binom{n}{r}a^{n-r}b^r$
# Part 1

>[!faq]- Factor completely: $16x^{-8}+24x^{-4}-8x^{-2}$
>Factor out the _GCF_ of $8x^{-8}$$$=8x^{-8}(2+3x^4-x^6)$$

>[!faq]- Factor completely: $2(x-1)^{\frac{1}{2}}+4(x-1)^{-\frac{1}{2}}$
>Factor out the _GCF_ of $2(x-1)^{-\frac{1}{2}}$: $$2(x-1)^{-\frac{1}{2}}[x-1+2]$$
>Simplify: $$2(x-1)^{-\frac{1}{2}}[x+1]$$

>[!faq]- Find $\frac{f(x+h)-f(x)}{h}$ for $f(x)=x^3-x^2$
>Plug in $f(x)$ into the formula above wherever there is an _x_.
>
>First $f(x+h)$: $$f(x+h)=x^3+3x^2h+3xh^2+h^3-x^2-2xh-h^2$$
>Second $-f(x)$: $$3x^2h+3xh^2+h^3-2xh-h^2$$
>Third divide by _h_: $$=3xh+3x^2+h^2-2x-h$$

>[!faq]- Decompose into partial fractions: $\frac{x+14}{(x-4)(x+2)}$
>Set up the partial fractions: $$\frac{x+14}{(x-4)(x+2)}=\frac{A}{x-4}+\frac{B}{x+2}$$
>Multiply both sides by $(x-4)(x+2)$ and cancel out: $$x+14=A(x+2)+B(x-4)$$
>Distribute: $$x+14=Ax+2A+Bx-4B$$
>$A+B=1$
>$2A-4B=14$
>Elimination method, to cancel out _A_ multiply by -2 $$\binom{-2A-2B=-2}{2A-4B=14}=-6B=12\to B=-2$$
>Now that you know _B_, plug it in and solve for _A_: $$A-2=1\to A=3$$
>Write in the partial fractions: $$\frac{3}{x-4}-\frac{2}{x+2}$$

>[!faq]- Decompose into partial fractions: $\frac{x-18}{(x-3)^2}$
>Set up partial fractions: $$\frac{x-18}{(x-3)^2}=\frac{A}{x-3}+\frac{B}{(x-3)^2}$$
>Multiply both sides by $(x-3)^2$: $$x-18=A(x-3)+B$$
>Distribute: $$x-18=Ax-3A+B$$
>$A=1$
>$-3A+B=-18$
>Since $A=1$ use substitution: $$-3(1)+B=-18\to B=-15$$
>Write in the partial fractions: $$\frac{1}{x-3}-\frac{15}{(x-3)^2}$$

>[!faq]- Decompose into partial fractions: $\frac{3x^2+17x+14}{(x-2)(x^2+2x+4)}$
>Set up partial fractions: $$\frac{3x^2+17x+14}{(x-2)(x^2+2x+4)}=\frac{A}{x-2}+\frac{Bx+C}{x^2}+2x+4$$
>Multiply both sides by $(x-2)(x^2+2x+4)$ and cancel out: $$3x^2+17x+14=A(x^2+2x+4)+(Bx+C)(x-2)$$
>Distribute: $$3x^2+17x+14=Ax^2+2Ax+4A+Bx^2+Cx-2Bx-2C$$
>$A+B=3$
>$2A-2B+C=17$
>$4A-2C=14$
>Use Elimination, multiply by 2 to cancel out _C_: $$\binom{4A-4B+2C=34}{4A-2C=14}=8A-4B=48$$
>Use Elimination, multiply by 4 to cancel out _B_: $$\binom{8A-4B=48}{4A+4B=12}=12A=60\to A=5$$
>Plug back in and solve for _B_: $$(5)+B=3\to B=-2$$
>Plug back in and solve for _C_: $$4(5)-2C=14\to C=3$$
>Write in the partial fractions: $$\frac{5}{x-2}+ \frac{-2x+3}{x^2+2x+4}$$

>[!faq]- Graph one complete period: $y=-2\sin\left( \frac{1}{2}x-\frac{\pi}{2} \right)$
>
>Amplitude: $\mid-2\mid=2$
>Period: $\frac{2\pi}{\frac{1}{2}}=4\pi$
>Reflected: Yes
>Phase Shift: Right $\frac{\frac{\pi}{2}}{\frac{1}{2}}=\pi$
>![[Pasted image 20240701094834.png]]

>[!faq]- Graph one complete period: $y=4\cos(3x+\pi)-2$
>
>Amplitude: $\mid4\mid=4$
>Period: $2\pi\to \frac{2\pi}{3}$
>Vertical Shift: Down $2$
>Phase Shift: Left $\pi\to \frac{\pi}{3}$
>![[Pasted image 20240701095449.png]]

>[!faq]- Graph one complete period: $y=\csc(2x-\pi)+1$
>
>Period: $2\pi\to \frac{2\pi}{2}=\pi$
>Vertical Shift: Up $1$
>Phase Shift: Right $\pi\to \frac{\pi}{2}$
>![[Pasted image 20240701100020.png]]

>[!faq]- Graph one complete period: $y=\sec \frac{1}{2}x-2$
>Period: $2\pi\to \frac{2\pi}{\frac{1}{2}}=4\pi$
>Vertical shift: Up $2$
>![[Pasted image 20240701100503.png]]

>[!faq]- Graph one complete period: $y=\tan \pi x+2$
>Period: $\pi\to \frac{\pi}{\pi}=1$
>Vertical shift: Up $2$
>![[Pasted image 20240701100810.png]]

>[!faq]- Graph one complete period: $-\cot\left( 3x+\frac{\pi}{2} \right)$
>Period: $\pi\to \frac{\pi}{3}$
>Reflected: Yes
>Phase shift: Left $\frac{\pi}{2}\to \frac{\frac{\pi}{2}}{3}=\frac{\pi}{6}$
>![[Pasted image 20240701101022.png]]

# Part 2

>[!faq]- State the domain and range in _interval notation_ for the following:
>
> >[!faq]- $y=\sin^{-1}x$
> >Domain:$[-1,1]$
> >Range:$\left[ -\frac{\pi}{2},\frac{\pi}{2} \right]$
>
>
> >[!faq]- $y=\cos^{-1}x$
> >Domain:$[-1,1]$
> >Range:$[0,\pi]$
>
>
> >[!faq]- $y=\tan^{-1}x$
> >Domain:$(-\infty,\infty)$
> >Range:$\left( -\frac{\pi}{2},\frac{\pi}{2} \right)$

>[!faq]- Give the exact value: $y=\sin \cos^{-1}\left( -\frac{2}{5} \right)$
>Remember:$$\cos=\frac{x}{r}=\frac{-2}{5}$$
>Place into Pythagorean Theorem: $$(-2)^2+b^2=5^2\to b=\sqrt{ 21 }$$
>Place values into the function $\sin=\frac{y}{r}$:$$y=\frac{\sqrt{ 21 }}{5}$$

>[!faq]- Give the exact value: $y=\sec \tan^{-1}\left( \frac{6}{7} \right)$
>Remember: $$\tan=\frac{y}{x}=\frac{6}{7}$$
>Place into Pythagorean Theorem: $$6^2+7^2=c^2\to c=\sqrt{ 85 }$$
>Place values into the function $\sec=\frac{r}{x}$: $$y=\frac{\sqrt{ 85 }}{7}$$

>[!faq]- Prove: $\frac{1}{1-\sin x}+\frac{1}{1+\sin x}=2\sec^2x$
>Cross multiply different denominators: $$\frac{1+\sin x+1-\sin x}{(1-\sin x)(1+\sin x)}$$
>Simplify: $$\frac{2}{1-\sin^2x}$$
>Pythagorean Identity [[Pythagorean Identities#^ff3cac]]: $$\frac{2}{\cos^2x}$$
>Take the reciprocal: $$2\sec^2x$$

>[!faq]- Prove: $\tan x\sin 2x=2-2\cos^2x$
>Rewrite in terms of sine and cosine: $$\frac{\sin x}{\cos x}*2\sin \cos x$$
>Cancel out from denominator: $$\sin x*2\sin x$$
>Multiply: $$2\sin^2x$$
>Factor out _2_: $$2(\sin^2x)$$
>Pythagorean Identity [[Pythagorean Identities#^ff3cac]]: $$2(1-\cos^2x)$$
>Distribute: $$2-2\cos^2x$$

>[!faq]- If $\sin A=-\frac{18}{17}$ and _A_ is in $Q_{3}$ and $\cos B=-\frac{5}{13}$ and _B_ is in $Q_{2}$, find the exact value of:
>
>Pythagorean Theorem to find:$\sin B=-\frac{15}{17}$ & $\cos A=\frac{12}{13}$
>
> >[!faq]- $\sin(A+B)$[[Sum & Difference Formulas#^2012b8]]
> >$$=-\frac{8}{17}*\left( -\frac{5}{13} \right)+\frac{12}{13}*\left( -\frac{15}{17} \right)$$
> >$$=\frac{40}{221}-\frac{180}{221}$$
> >$$=-\frac{140}{221}$$
>
>
> >[!faq]- $\cos 2A$[[Double Angle Formulas#^5341cb]]
> >$$=\left( -\frac{15}{17} \right)^2-\left( -\frac{8}{17} \right)^2$$
> >$$=\frac{225}{289}-\frac{64}{289}$$
> >$$=\frac{161}{289}$$
>
>
> >[!faq]- $\tan \frac{1}{2}B$[[Half-Angle Formulas#^a0b66a]]
> >Remember $\tan B$ is in $Q_{1}$
> >$$=\sqrt{ \frac{1+\frac{15}{13}}{1-\frac{15}{13}} }$$
> >$$=\sqrt{ \frac{\frac{18}{13}}{\frac{8}{13}} }$$
> >$$\sqrt{ \frac{9}{4} }=\frac{3}{2}$$

>[!faq]- Find all the solutions to $-3\sec x+2\sqrt{ 3 }=0$ in _radian measure_
>Solve for $\sec x$: $$-3\sec x+2\sqrt{ 3 }=0\to -3\sec x=-2\sqrt{ 3 }\to \sec x=\frac{2\sqrt{ 3 }}{3}$$
>It's easier if you convert to $\cos$: $$\frac{2\sqrt{ 3 }}{3}\to \frac{3}{2\sqrt{ 3 }}\to \frac{3\sqrt{ 3 }}{6}\to \frac{\sqrt{ 3 }}{2}$$
>Find where $\cos x=\frac{\sqrt{ 3 }}{2}$: $$x_{1}=\frac{\pi}{6}$$
>$$\frac{\pi}{6}+2\pi k,\frac{11\pi}{6}+2\pi k$$

>[!faq]- Use the quadratic formula to solve $2\tan^2x-\tan x-5=0$ over $[0\degree,360\degree)$, rounded to _two_ decimal places.
>Find the a, b, & c:
> >$a=2$
> >$b=-1$
> >$c=-5$
>
>Plug into the quadratic formula [[the-quadratic-formula-and-the-values-of-discriminant.webp]]: $$\tan x=\frac{-(-1)\pm \sqrt{ (-1)^2-4(2)(-5) }}{2(2)}$$
>Solve the formula in decimal form: $$=\frac{1\pm6.403}{4}$$
>Find the angles for the positive:
> >$$\tan x=\frac{7.403}{4}$$
> >$x_{1}=61.62\degree$
> >$x_{2}=61.62+180=241.62$
> >$x=61.62\degree,241.62\degree$
>
>
>Find the angles for the negative:
> >$$\tan x=\frac{-5.403}{4}$$
> >$$x_{1}=-53.49\to -53.49+180=126.51\degree$$
> >$x_{2}=126.51+180=306.51\degree$
> >$x=126.51\degree,306.51\degree$

>[!faq]- Find all the solution to $\sin 3x=1$ in _radian measure_
>Let $u=3x$
>$$\sin u=1$$
>$$u=\frac{\pi}{2}+2\pi k$$
>$$3x=\frac{\pi}{2}2\pi k$$
>$$x=\frac{\pi}{6}+\frac{2\pi k}{3}$$

# Part 3

>[!faq]- Change to _polar form_: $\sqrt{ 3 }-i$
>Notice that it is in $Q_{4}$
>Find the value of _r_: $$r=\sqrt{ (\sqrt{ 3 })^2 +1^2}=2$$
>Find the value of $\theta$: $$\tan \theta=\mid-\frac{1}{\sqrt{ 3 }}\mid\to \frac{\sqrt{ 3 }}{3}$$
>Find the inverse in $Q_{4}$: $$\tan^{-1}\frac{\sqrt{ 3 }}{3}=330\degree$$
>$$=2(\cos 330\degree+i\sin 330\degree)$$

>[!faq]- Change to _polar form_: $-6+6i$
>Notice it's in $Q_{2}$
>Find _r_: $$r=\sqrt{ (-6)^2+6^2 }\to 6\sqrt{ 2 }$$
>Find $\theta$ in the $Q_{2}$: $$\tan \theta=-\frac{6}{6}\to -1=135\degree$$
>Plug in: $$6\sqrt{ 2 }(\cos 135\degree+i\sin135\degree)$$

>[!faq]- Change to _rectangular form_: $4\left( \cos \frac{\pi}{3}+i\sin \frac{\pi}{3} \right)$
>Find the $\cos$ for $a$:
> >$4\cos \frac{\pi}{3}=a$
> >$4\left( \frac{1}{2} \right)=a$
> >$2=a$
>
>Find the $\sin$ for $b$:
> >$4\sin \frac{\pi}{3}=b$
> >$4\left( \frac{\sqrt{ 3 }}{2} \right)=b$
> >$2\sqrt{ 3 }=b$
>
>Plug it in: $$2+2\sqrt{ 3 }i$$

>[!faq]- Change to _rectangular form_: $2(\cos 270\degree+i\sin 270\degree)$
>Find the $\cos$ for $a$:
> >$2\cos270\degree=a$
> >$2(0)=a$
> >$a=0$
>
>Find the $\sin$ for $a$:
> >$2\sin 270\degree=b$
> >$2(-1)=b$
> >$b=-2$
>
>Plug it in: $$-2i$$

>[!faq]- Use the DeMoivre's Theorem to find: $$\left[ 2\left( \cos \frac{\pi}{6}+i\sin \frac{\pi}{6} \right) \right]^6$$
>Plug it into DeMoivre's Theorem: $$2^6\left( 6*\frac{\pi}{6}+6*\frac{\pi}{6} \right)$$
>$$=64(\cos \pi+i\sin \pi)$$

>[!faq]- Use $^n\sqrt{ z }=^n\sqrt{ r }\left[ \cos\left( \frac{\theta+2\pi k}{n}+i\sin\left( \frac{\theta+2\pi k}{n} \right) \right) \right]$ to find the three cube roots of $8\left( \cos \frac{\pi}{4}+i\sin \frac{\pi}{4} \right)$
>Plug it into your formula: $$2\left[ \cos \left( \frac{\pi}{4}+\frac{2\pi k}{3} \right)+i\sin\left( \frac{\pi}{4}+\frac{2\pi k}{3} \right) \right]$$
>Now find it with _k_ at _three_ values:
> >$k=0\to 2\left( \cos \frac{\pi}{12}+i\sin \frac{\pi}{12} \right)$
> >$k=1\to 2\left( \cos \frac{3\pi}{4}+i\sin \frac{3\pi}{4} \right)$
> >$k=2\to 2\left( \cos \frac{17\pi}{12}+i\sin \frac{17\pi}{12} \right)$

>[!faq]- For each ellipse find the following:
>
> >[!faq]- Write in standard form:
> >Subtract 48 from both sides: $$4x^2-24x+y^2-8y=-48$$
> >Factor _x_ & _y_, then multiply the coefficient by _C_ and add to the right side for both _x_ and _y_: $$4(x^2-6x+9)+(y^2-8y+16)=-48+36+16$$
> >Lose _C_ and take half of _B_ for the constant: $$4(x-3)^2+(y-4)^2=4$$
> >Divide both sides by _4_: $$\frac{(x-3)^2}{1}+\frac{(y-4)^2}{4}=1$$
>
>
> >[!faq]- State the coordinates of the _vertices_:
> >This is an ellipse, so the _denominator_ determines that this one is _vertical_
> >Add and subtract _2_ from the _y_ of the center: $$a^2=4\to a=\pm2\to(3,2),(3,6)$$
>
>
> >[!faq]- State the coordinates of the _foci_:
> >Find the _c_: $$c^2=b^2-a^2\to c^2=3\to c=\pm \sqrt{ 3 }$$
> >Add _c_ to the center on the _major axis_: $$(3,4-\sqrt{ 3 }),(3,4+\sqrt{ 3 })$$
>
>
> >[!faq]- State the lengths of the _major_ and _minor_ axes:
> >Major$=2(b)$
> >$$2(2)=4$$
> >Minor$=2(a)$
> >$$2(1)=2$$
>
>
> >[!faq]- Use the reference rectangle to sketch the graph:
> >![[Pasted image 20240701135228.png]]

>[!faq]- For each hyperbola find the following:
> >[!faq]- Write in standard form:
> >Add 489 to both sides, factor, $c=\left( \frac{1}{2}b \right)^2$, and add the coefficient times _c_ to the other side: $$4(x^2-6x+9)-25(y^2-10y+25)=489+36-625$$
> >Take $\frac{1}{2}b$ for for constant: $$4(x-3)^2-25(y-5)^2=-100$$
> >Divide both sides by $-100$: $$-\frac{(x-3)^2}{25}+\frac{(y-5)^2}{4}=1$$
>
>
> >[!faq]- State the coordinates of the _center_:
> >$(x-3)\to x=3$
> >$(y-5)\to y=5$
> >$(3,5)$
>
>
> >[!faq]- State the coordinates of the _vertices_:
> >Find b:
> >$b^2=25$
> >$b=\pm 5$
> >Find the pair for plus and minus: $(-2,5),(8,5)$
>
>
> >[!faq]- State the coordinates of the _pseudo-vertices_:
> >Find a:
> >$a^2=4$
> >$a=\pm2$
> >Find the pair for plus and minus: $(3,3),(3,7)$
>
>
> >[!faq]- State the coordinates of the _foci_:
> >Find _c_, then add and subtract it from the _major_ side, which is _vertical_ because the _y_ is the positive side in standard form
> >$c^2=a^2+b^2$
> >$c^2=29$
> >$c=\pm \sqrt{ 29 }$
> >$(3,5-\sqrt{ 29 }),(3,5+\sqrt{ 29 })$
>
>
> >[!faq]- Give the equation of each asymptote and graph:
> >Remember: $y-(k)=\pm\frac{b}{a}(x-(h))$ and solve for _y_
> >Positive: $y=\frac{2}{5}x+\frac{19}{5}$
> >Negative: $y=-\frac{2}{5}x+\frac{31}{5}$
> >![[Pasted image 20240701142552.png]]
> 

>[!faq]- Solve each oblique triangle. Round to the nearest tenth $A=70.1,B=55.2,a=12.1$
>All triangles angles add to 180$$C=180-70.1-55.2=54.7$$
>Find the sides using the Law of Sines $$\frac{12.1}{\sin70.1}=\frac{b}{\sin55.2}\to b=\frac{12.1*\sin55.2}{\sin 70.1}=10.6$$
>Find the sides using the Law of Sines $$\frac{12.1}{\sin 70.1}=\frac{c}{\sin 54.7}\to c=\frac{12.1*\sin 54.7}{\sin 70.1}=10.5$$

>[!faq]- Solve each oblique triangle. Round to the nearest tenth $A=102.7,C=30.1,c=12.6$
>All triangles angles add to180 $$C=180-102.7-30.1=47.2$$
>Use the Law of Sines for _a_ $$\frac{12.6}{\sin 30.1}=\frac{a}{\sin 102.7}\to a=\frac{12.6*\sin 102.7}{\sin 30.1}=24.5$$
>Use the Law of Sines for _b_ $$\frac{12.6}{\sin 30.1}=\frac{a}{\sin 47.2}\to a=\frac{12.6*\sin 47.2}{\sin 30.1}=18.4$$

>[!faq]- Solve each oblique triangle. Round to the nearest tenth $a=3.8,b=4.2,c=4.0$
>Find the longest angle first with the [[law-of-cosines.png]], _B_: 
$$4.2^2=3.8^2+4^2-2(3.8)(4)\cos B$$
>Simplify:$$17.64=14.44+16-30.4\cos B$$
>Subtract from both sides: $$-12.8=-30.4\cos B$$
>Divide from both sides and take the inverse: $$\frac{12.8}{30.4}=\cos B\to B=65.1\degree$$
>Use the [[Law of Sines]]: $$\frac{4.2}{\sin 65.1}=\frac{3.8}{\sin A}\to A=\frac{3.8*\sin 65.1}{4.2}\to A=55.2\degree$$
>Find the last angle with triangle law: $$C=180-55.2-65.1\to C=59.7\degree$$

# Part 4

>[!faq]- Write the first _four_ terms of $a^n=\frac{(-1)^{n+1}}{2^n-1}$
>$$a_{1}=\frac{(-1)^2}{2-1}=1$$
>$$a_{2}=\frac{(-1)^3}{2^2-1}=-\frac{1}{3}$$
>$$a_{3}=\frac{(-1)^4}{2^3-1}=\frac{1}{7}$$
>$$a_{4}=\frac{(-1)^5}{2^4-1}=-\frac{1}{15}$$

>[!faq]- Write the first _four_ terms of $a_{1}=5$ and $a_{n}=3a_{n-1}-1$
>$$a_{1}=5$$
>$$a_{2}=14$$
>$$a_{3}=41$$
>$$a_{4}=122$$

>[!faq]- Write the first _four_ terms of $a_{n}=-2(n-1)!$
>$0!$ is equal to _1_: $$a_{1}=-2(0)!\to-2(1)=-2$$
>$$a_{2}=-2(1)!\to -2(1)=-2$$
>Factorial comes before multiplication: $$a_{3}=-2(2)!\to-2(2)=-4$$
>$$a_{4}=-2(3)!\to-2(6)=-12$$

>[!faq]- Use the $a_{n}$ formula to find: $a_{100}$ if $a_{1}=5,d=-3$
>The formula goes $a_{n}=a_{1}+(n-1)d$
>Plug into formula and solve: $$a_{100}=5+(100-1)(-3)\to 5+99(-3)=-292$$

>[!faq]- Use the $a_{n}$ formula to find: $a_{75}$ for the _arithmetic sequence_ $3,-8,-19,\dots$
>Find the information to fill the formula:
> >$a_{1}=3$
> >$d=-11$
>
>Plug into the formula and solve: $$a_{75}=3+(75-1)(-11)\to 3+74(-11)=-811$$

>[!faq]- Find the sum of the first 50 terms of the _arithmetic series_: $5+12+19+\dots$
>First, find the information you'll need to plug:
> >$a_{1}=5$
> >$d=7$
> >
>Then find the arithmetic sequence to _n_ using the $a_{n}$ formula: $$a_{50}=5+(50-1)(7)\to 5+49(7)=348$$
>Now use the arithmetic sequence formula: $$S_{50}=\frac{50}{2}(5+348)=8825$$

>[!faq]- For each _parabola_: $x^2+4x+8y-4$
> >[!faq]- Write in standard form:
> >Separate the _x_ and the _y_ by subtracting and adding to both sides, as well as the _C_: $$(x^2+4x+4)=-8y+4+4$$
> >Simplify: $$(x+2)^2=-8y+8$$
> >Factor: $$(x+2)^2=-8(y-1)$$
>
>
> >[!faq]- State the direction:
> >_Vertical_ that opens _down_
>
>
> >[!faq]- State the coordinates of the _vertex_:
> >$x+2,y-1$
> >$(-2,1)$
>
>
> >[!faq]- State the equation of the _axis of symmetry_ :
> >Find _p_: $4p=-8\to p=-2$
> >Place on the perpendicular coordinate: $x=-2$
>
>
> >[!faq]- State the coordinates of the _focus_:
> >Take the _vertex_ + _P_ on it's opening coordinate:
> >$(-2,-1)$
>
>
> >[!faq]- Give the equation of _directerix_:
> >Go _p_ units in the _opposite direction_ of the _focus_ from the _vertex_.
> >$y=3$
>
>
> >[!faq]- State the coordinates of the endpoints of the focal chord and graph:
> >The _Focus$+\frac{4(p)}{2}$ perpendicular to the direction the parabola opens
> >$(-2,-1)\to h\pm4$
> >$=(-6,-1),(2,-1)$
> >![[Pasted image 20240702105133.png]]

>[!faq]- Find the coordinates of the point with parametric equations: $x=(60\cos 30\degree)t,y=5+(50\sin 30\degree)t-16t^2,t=2$
>Solve for _x_: $$x=\left( 60*\frac{\sqrt{ 3 }}{2} \right)*2\to 60\sqrt{ 3 }$$
>Solve for _y_: $$y=5+\left( 60*\frac{1}{2} \right)(2)-16(2)^2\to 5+30(2)-64=1$$
>$$=(60\sqrt{ 3 },1)$$

>[!faq]- Plot the points described by the parametric equations: $x=t,y=2t+2,-2\leq t\leq 3$
>Use the formulas across the range to get the coordinates:
> >$(-5,-2)$
> >$(-4,0)$
> >$(-3,2)$
> >$(-2,4)$
> >$(-1,6)$
> >$(0,8)$
>
>Plot the points and it's a line

>[!faq]- Eliminate the parameter _t_: $x=3t-5,y=4t^2$
>Solve for _t_ on the _x_: $$3t=x+5\to t=\frac{1}{3}x+\frac{5}{3}$$
>Solve for _y_ with _t_ substitution: $$y=4\left( \frac{1}{3}x+\frac{5}{3} \right)^2$$
>Distribute the square and foil: $$=4\left( \frac{1}{9}x^2+\frac{10}{9}x+\frac{25}{9} \right)$$
>Distribute the _4_: $$y=\frac{4}{9}x^2+\frac{40}{9}x+\frac{100}{9}$$