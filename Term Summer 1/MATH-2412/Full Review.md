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


