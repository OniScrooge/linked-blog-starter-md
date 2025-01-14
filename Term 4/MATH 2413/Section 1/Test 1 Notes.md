# Related
Prev - [[Test 2 Notes]]
# Content
>[!faq]- Find the limit of $\lim_{ x \to 9^+ }\frac{\mid9-x\mid}{9-x}$
>Substitute: $$\frac{\mid 9-(9)\mid}{9-(9)}$$
>Or calculator: _limit(abs(9-x)/(9-x),x,9,1)_ The one(or negative one) indicates direction
>
>Simplify and remember it comes from the right: $$\frac{0}{0}=-1$$

>[!faq]- Find the limit of $\lim_{ x \to 0 }\frac{x^2-2x+\sin x}{x}$
>Separate out: $$\frac{x^2}{x}-\frac{2x}{x}+\frac{\sin x}{x}$$
>Simplify: $$x-2+\frac{\sin x}{x}$$
>Substitute: $$(0)-2+\frac{\sin(0)}{0}$$
>Simplify: $$-2+\frac{0}{0}$$
>$$-2+1$$
>$$-1$$

>[!faq]- Find the vertical asymptotes of $f(x)=\frac{x-3}{9x-x^3}$
>Factor out __x__: $$\frac{x-3}{x(9-x^2)}$$
>Separate the binomial: $$\frac{x-3}{x(x-3)(x+3)}$$
>Like terms: $$\frac{1}{x(x+3)}$$
>Take both and set them equal to __0__: $$x=0$$
>$$x+3=0$$
>Find __x__ for both: $$x=0$$
>$$x=-3$$

>[!faq]- Find the vertical asymptotes of $f(x)=\frac{-x^2+16}{x^2+5x+4}$
>Factor out negative: $$\frac{x^2-16}{x^2+5x+4}$$
>Factor numerator: $$\frac{(x-4)(x+4)}{x^2+5x+4}$$
>Factor denominator: $$\frac{(x-4)(x+4)}{(x+1)(x+4)}$$
>Like terms: $$\frac{(x-4)}{(x+1)}$$
>Set equal to __0__ and solve: $$x=4,x=-1$$
>Plug back in and check: $$(4)^2-16=0$$
>__4__ can't work, so that just leaves __-1__ which does.

>[!faq]- Find the [[derivative]] of $y=\frac{x^3+8x+3}{\sqrt{ x }}$
>Change denominator: $$=\frac{x^3+8x+3}{x^{\frac{1}{2}}}$$
>Move to numerator: $$=x^3+8x+3+x^{\frac{-1}{2}}$$
>[[2.2 Basic Differentiation rules#^f175ee]] Power rule: $$=x^3+8x+3-\frac{1}{2}x^{\frac{-3}{2}}$$
>Move to denominator: $$\frac{5x^2+8x-3}{2x^{\frac{3}{2}}}$$

>[!faq]- Find the limit of $\lim_{ x \to 4 }(x-[\mid x\mid])$
>Find the [[1.4 Continuity and One-Sided Limits#^522e79]] __GIF__: $$[\mid(4)\mid]=4$$
>Substitute and solve: $$(4)-(4)=0$$

>[!faq]- Find the [[derivative]] of $f(x)=\frac{2}{^3\sqrt{ x }}+6\cos x$
>Rewrite the denominator: $$\frac{2}{x^{\frac{1}{3}}}+6\cos x$$
>Move to the numerator: $$2*\frac{1}{3}x^{-\frac{2}{3}}+6\cos x$$
>Power rule: $$-\frac{2}{3}x^{-\frac{4}{3}}+6\cos x$$
>Move to denominator and apply cosine [[derivative]]: $$-\frac{2}{3x^{\frac{4}{3}}}-6\sin x$$

>[!faq]- Find the slope of $y=x^2+4x,x=7$
>Find the [[derivative]]: $$=2x+4$$
>Substitute in __7__ for __x__: $$=2(7)+4$$
>Solve: $$=14+4$$
>$$m=18$$

>[!faq]- Find k in $$f(x)=\{ \begin{eqnarray*} & x^2,x\leq 3 \\ &x+k,x>3 \\  \end{eqnarray*}$$
>Plug in: $$(3)^2=9$$
>$$(3)+k$$
>Set equal to __9__: $$3+k=9$$
>$$k=6$$

>[!faq]- Find the horizontal tangents of $f(x)=x^3-21x$
>Differentiate: $$3x^2-21$$
>Set equal to __0__: $$3x^2-21=0$$
>Divide out __3__: $$x^2-7=0$$
>Add __7__: $$x^2=7$$
>Take the square: $$x=\sqrt{ 7 }$$
>Substitute positive __x__ back into the [[function]]: $$(\sqrt{ 7 })^3-21(\sqrt{ 7 })$$
>Simplify: $$7\sqrt{ 7 }-21\sqrt{ 7 }=-14\sqrt{ 7 }$$
>Substitute negative x back into the [[function]]: $$(-\sqrt{ 7 })^3-21(-\sqrt{ 7 })$$
>Simplify: $$-7\sqrt{ 7 }+21\sqrt{ 7 }=14\sqrt{ 7 }$$
>The horizontal tangent points are at: $(\sqrt{ 7 },-14\sqrt{ 7 })(-\sqrt{ 7 },14\sqrt{ 7 })$

>[!faq]- Find the [[derivative]] using $\lim_{ x \to c }\frac{f(x)-f(c)}{x-c}$, $c=1$, $f(x)=10\sqrt{ x }$
>Get $f(c)$: $$f(c)=10*\sqrt{ (1) }=10*1=10$$
>Plug in: $$f'(1)=\frac{10\sqrt{ x }-10}{x-1}$$
>Simplify: $$\lim_{ x \to 1 }\frac{10(\sqrt{ x }-1)}{x-1}$$
>$$\lim_{ x \to 1 } \frac{10(\sqrt{ x }-1)(\sqrt{ x }-1)}{(x-1)(\sqrt{ x }+1)}$$
>$$\lim_{ x \to 1 } \frac{10(x-1)}{(x-1)(x+1)}$$
>$$\lim_{ x \to 1 } \frac{10}{\sqrt{ x }+1}$$
>Evaluate: $$\lim_{ x \to 1 } \frac{10}{\sqrt{ 1 }+1}$$
>$$\lim_{ x \to 1 } \frac{10}{2}=5$$