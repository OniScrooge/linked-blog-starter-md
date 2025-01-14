# Related
Prev - [[Test 1 Notes]]

Next - [[Test 3 Notes]]
# Content

>[!faq]- Find dy/dt in $y=\cos^3(\pi t-13)$
>Differentiate in calc: $$-3\pi \cos^2(\pi t-13)\sin(\pi t-13)$$

>[!faq]- Determine whether the function satisfies the hypotheses of the Mean Value Theorem for the given interval. $g(x)=x^{3/4},[0,1]$
>Continuity on $[0,1]$:
>- The function $g(x)=x^{3/4}$ is continuous for all $x\geq 0$, since it is a well-defined power function.
>- On $[0,1]$, $g(x)$ is continuous.
>
>Differentiability on $(0,1)$:
>Find the derivative of $g(x)$: $$g'(x)=\frac{3}{4}x^{-1/4}$$
>The derivative of $g'(x)$ is undefined at $x=0$, since $x^{-1/4}\to \infty$ as $\to 0^+$
>Thus, $g(x)$ is not differentiable at $x=0$, although it is differentiable on $(0,1)$
>
>Answer is __no__.

>[!faq]- Water is falling on a surface, wetting a circular area that is expanding at a rate of $8mm^2/s$. How fast is the radius of the wetted area expanding when the radius is $174mm$? (Round to four decimal places)
>$A=\pi r^2$
>Differentiate with respect to time: $$\frac{dA}{dt}=2\pi \frac{dr}{dt}$$
>- $\frac{dA}{dt} = 8mm^2 /s$
>- $r=174mm$
>- $\frac{dr}{dt}=?$
>
>Rearrange to solve for $\frac{dr}{dt}$: 
>$$\frac{dr}{dt}=\frac{\frac{dA}{dt}}{2\pi r}$$
>Substitute the known values: $$\frac{dr}{dt}=\frac{8}{2\pi*174}$$
>Simplify: $\frac{dr}{dt}=\frac{8}{348\pi}\approx \frac{8}{1093.25}\approx 0.00732mm /s$
>$$0.0073mm /s$$

>[!faq]- Using the derivative of _f(x)_ given below, determine the intervals on which _f(x)_ is increasing or decreasing. $f'(x)=(6-x)(8-x)$
>Plug into calculator
>Regions above the _x-axis_ is increasing: $(-\infty,6)U(8,\infty)$
>Regions below the _x-axis_ is decreasing: $(6,8)$

>[!faq]- If $xy+x=12$ and $\frac{dx}{dt}=-3$, then what is $\frac{dy}{dt}$ when $x=2$ and $y=5$?
>- $\frac{dx}{dt}=-3$
>- $x=2$
>- $y=5$
>Differentiate $xy+x=12$: $$\frac{d}{dt}(xy)+\frac{d}{dt}(x)=\frac{d}{dt}(12)$$ 
>$$\frac{dx}{dt}y+x\frac{dy}{dt}+\frac{dx}{dt}=0$$
>Substitute known values: $$(-3)(5)+(2)\frac{dy}{dt}+(-3)=0$$
>Simplify: $$-15+2\frac{dy}{dt}-3=0$$
>$$-18+2\frac{dy}{dt}=0$$
>$$2\frac{dy}{dt}=18$$
>$$\frac{dy}{dt}=9$$

>[!faq]- Determine all critical points for the function: $f(x)=x^3-12x+3$
>Differentiate in calculator: $$3x^2-12$$
>Use algebra solve function: $solve(3x^2-12=0,x)$
>$$x=-2,2$$

>[!faq]- Find the value or values of _c_ that satisfy the equation $\frac{f(b)-f(a)}{b-a}=f'(c)$ in the conclusion of the Mean Value Formula of the function and interval. $f(x)=x+\frac{18}{x},[2,9]$
>Plug into the formula: $$\frac{\left( 9+\frac{18}{9} \right)-\left( 2+\frac{18}{2} \right)}{9-2}=0$$
>Differentiate $f(x)$ and set equal to _0_ from above: $$1-\frac{18}{x^2}=0$$
>Solve for _x_: $$\frac{18}{x^2}=1$$
>$$x^2=18$$
>$x=\pm \sqrt{ 18 }=\pm3\sqrt{ 2 }$
>Since _c_ is between $(2,9)$ then it must be positive: $$3\sqrt{ 2 }$$

>[!faq]- Use implicit differentiation to find $\frac{dy}{dx}$ and $\frac{d^2y}{dx^2}$: $x^2+y^2=5,(2,1)$
>Implicit Diff on calculator with the formula, then the two variables, then plug in: $$-\frac{x}{y}$$
>$$\frac{dy}{dx}=\frac{-2}{1}=-2$$
>Implicit diff on calculator with the formula, then the two variables, then a 2 for the second derivative, then plug in: $$\frac{dy}{dx}=-\frac{x^2}{y^3}-\frac{1}{y}$$
>$$\frac{-2^2}{1^3}-\frac{1}{1}=-5$$
>$$\frac{dy}{dx}=-2,\frac{d^2y}{dx^2}=-5$$

>[!faq]- At the given point, find the line that is tangent to the curve, or the line that is normal to the curve, as requested: $y^4+x^3=y^2+9x$, normal at $(0,1)$
>Implicit Diff the equation, then plug in: $$\frac{-3(x^2-3)}{2y(2y^2-1)}$$
>$$\frac{-3((0)^2-3)}{2(1)(2(1)^2-1)}=\frac{9}{2}$$
>This gives you the slope of tangent, but this is asking for normal, so it becomes a _negative reciprocal_: $$m=-\frac{2}{9}$$
>Plug into the slop formula $y-k=m(x-h)$: $$y-(1)=\left( -\frac{2}{9} \right)(x-0)$$
>Solve:
>$$y=-\frac{2}{9}x+1$$

>[!faq]- Find an equation for the tangent to the curve $y=\frac{18}{x^2+2}$ at the point $(1,6)$
>Differentiate: $$\frac{-36x}{(x^2+2)^2}$$
>Plug in: $$\frac{-36(1)}{((1)^2+2)^2}=-\frac{36}{9}=-4$$
>The slope is _-4_ on the tangent, so unlike a _normal_ you don't need to change it.
>Plug into slope formula $y-k=m(x-h)$ and solve: $$y-6=-4(x-1)$$
>$$y=-4x+10$$