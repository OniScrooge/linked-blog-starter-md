# Related
Prev - [[Test 3 Notes]]

# Content
>[!faq]- Evaluate the integral: $\int \csc^2(4\theta+5) \, d\theta$
>Plug into calculator
>Result is: $$-\frac{1}{4\tan (4\theta+5)}$$
>Note that tan is in the denominator, if separated it'd look like this: $$-\frac{1}{4}*\frac{1}{\tan(4\theta+5)}$$
>This is effectively: $$-\frac{1}{4}*\cot(4\theta+5)$$
>Don't forget the constant, answer: $$-\frac{1}{4}\cot(4\theta+5)+C$$

>[!faq]- Find the exact value of the total area of the region between the curve and the _x-axis_: $y=-x^2+9;0\leq x\leq 5$
>Use calculator to integrate for _x_ from _0_ to _5_: $$\int ^5_{0} \,-x^2+9$$
>Answer: $10/3$

>[!faq]- Solve the initial value problem: $\frac{dy}{dx}=\sin(2x+\pi),y(0)=2$
>Use calculator to integrate: $$\frac{\cos(2x)}{2}$$
>Substitute in for _x_: $$\frac{\cos(2(0))}{2}=\frac{1}{2}$$
>It says that $y(0)=2$, so whatever is added to $\frac{1}{2}$ is the _C_.
>Integral rule is: $$\int \sin(ax+b) \, dx =-\frac{1}{a}\cos(ax+b)+C$$
>Answer: $$y=-\frac{1}{2}\cos(2x+\pi)+\frac{3}{2}$$

>[!faq]- Find the exact value of the area represented by the definite integral: $\int^3_{0} \mid x-2\mid \, dx$
>Integrate using calculator with absolute: _f(abs(x-2),x,0,3)_
>Answer: $$\frac{5}{2}$$

>[!faq]- Find the average value of the function over the given interval: $f(x)=8-x$ on $[0,8]$
>_Average value_ is calculated with: $$\frac{1}{b-a}$$ on $$\int^b_{a} f(x)\, dx$$
>Get Average Value: $$\frac{1}{8-0}=\frac{1}{8}$$
>Plug in and calculate: $$\frac{1}{8}*\int^8_{0} 8-x \, dx$$
>Answer: $$4$$

>[!faq]- Find $\frac{dy}{dx}$: $e^{2y}=\cos(5x+y)$
>Anytime you see it 2 things equal to another you need to use implicit differentiation.
>Use in calculator: $$imDif(e^{2y}=\cos(5x+y),x,y)$$
>Answer: $$\frac{-5\sin(5x+y)}{2e^{2y}+\sin(5x+y)}$$

>[!faq]- Find an equation of the line tangent to the given curve at the point $(a, f(a))$: $f(x)=-6e^{3x},a=0$
>Solve for $x=0$: $$-6e^{3(0)}=-6$$
>Differentiate $-6e^{3x}$: $$\frac{d}{dx}(-6e^{3x})=-18e^{3x}$$
>Solve for $x=0$: $-18e^{3(0)}=-18$
>Put into the slope formula $y-k=m(x-h)$: $$y-(-6)=-18(x-0)$$
>Distribute: $$y+6=-18x$$
>Subtract: $$y=-18x-6$$
>Answer: $$y=-18x-6$$

>[!faq]- Evaluate the integral: $\int \frac{dx}{x(4+6\ln x)} \, dx$
>Integrate in calculator: $$f\left( \frac{1}{x(4+6\log(x))} \right)$$
>Returns this, which is just a simplified version of the answer if you look: $$\frac{\ln(3\ln(x)+2)}{6}$$
>__Don't forget the constant__
>Answer: $$\frac{1}{6}\ln\mid4+6\ln x\mid+C$$

