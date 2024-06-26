# Summary
# Related
Next - [[1.2 Partial Fractions]]
# Content

>[!abstract] Factoring explained
>A two-year-old boy is asked, "Do you have a brother?" He answers, "Yes." "What is your brother's name?" "Tom." Asked if Tim has a brother, the two-year-old replies, "No." The child can go in the direction from self to brother, but he cannot reverse this direction and move from brother back to self.
>
>As out intellects develop, we learn to reverse the direction of our thinking. Reversibility of thought is found throughout algebra. For example, we can multiply polynomials and show that:
>$$5x(2x+3)=10x^2+15x$$
>We can also reverse this process and express the resulting polynomial as:
>$$10x^2+15x=5x(2+3)$$

__Factoring__ a polynomial expressed as the sum of monomials means finding an equivalent expression that is a product.

$$Factoring:10x^2+15x$$
- __+__ - Sum of monomials
- __5x(2x+3)__ - The factors of $10x^2+15x$ are $5x$ and $2x+3$.
- __5x(2x__ - Equivalent expression that is a product

In this section, we will be _factoring over the set of integers_, meaning that the coefficients in the factors are integers. Polynomials that cannot be factored using integer coefficients are called _irreducible over the integers_, or __prime__.

The goal in factoring a polynomial is to use one or more factoring techniques until each of the polynomial's factors, except possibly for a monomial factor, is prime or irreducible. In this situation, the polynomial is said to be _factored completely_. We will now discuss basic techniques for factoring polynomials.

## Common factors

In any factoring problem, the first step is to look for the [[Greatest Common Factor]] or __GCF__. The distributive property in the reverse direction can be used to factor out the _GCF_.
$$ab+ac=a(b+c)$$

>[!note] Given $16a^{6}+24a^{8}-12a^{10}$
>The __GCF__ for this equation is $4a^6$ as the _coefficients_ are all divisible by a common factor of 4, with __a__, and the power of 6 being the lowest amongst the powers available.
> - $\frac{16a^6}{4a^6}\to \frac{16}{4}*a^{6-6}=4$
> - $\frac{24a^8}{4a^6}\to \frac{24}{4}*a^{8-6}=6a^2$
> - $-\frac{12a^{10}}{4a^6}\to -\frac{12}{4}*a^{10-6}=-3a^4$
>
>This can be factored to $=4a^{6}(4+6a^{2}-3a^{4})$
>
>Suppose that now you're given $x^{3/4}-x^{1/4}$
>$x^{3/4}-x^{1/4}$ Divide both be $x^{\frac{1}{4}}$
>$12x^{-3/4}+6x^{1/4}$ Divide out $6x^{-3/4}$
>
>And you get $6x^{-\frac{3}{4}}(2+x)$

>[!faq] - Factor completely: $18x^3+27x^2$
>The __GCF__ is: $9x^2$ as 9 is the largest number to divide evenly into 18 and 27 and 2 is the lowest of the powers available.
>
>$\frac{18}{9},3-(+2)=2x$
>$\frac{27}{9},2-(+2)=3$
>
>So this factors to:
>$$9x^2(2x+3)$$

>[!info] Negative Exponents
>Be sure to read instructions carefully. Sometimes on exams and in the homework, you will be asked to leave __NO NEGATIVE EXPONENTS__.
>
>If you do have a negative exponent you will need to use the rule $a^{-x}=\frac{1}{a^{x}}$

>[!faq]- Given $(4x+3)^{2}+10(5x+1)(4x+3)$
>Find the greatest common factor to be $2(4x+3)^{-2}$.
>$$2(4x+3)^{-2}[-4+5(5x+1)(4x+3)]$$
>Now factor the latter part
>$$2(4x+3)^{-2}[-4+100^{2}+75x+20x+15]$$
>Simplify
>$$2(4x+3)^{-2}(100x^{2}+95x+11)$$
>If this is wanted to be without a negative exponent it would be
>$$\frac{100x^{2}+95x+11}{(4x+3)^{2}}$$
>Note that the 2 doesn't come with it

>[!faq]- Given $4(x+5)^{-\frac{3}{2}}-\frac{3}{2}(4x+7)(x+5)^{-\frac{5}{2}}$
>Common factor is $(x+5)^{\frac{-5}{2}}$
>$$(x+5)^{-\frac{5}{2}}\left[ 4(x+5)-\frac{3}{2}(4x+7) \right]$$
>Simplify
>$$(x+5)^{\frac{-5}{2}}\left( 4x+\frac{40}{2}-6x-\frac{21}{2} \right)$$
>Simplify further
>$$(x+5)^{\frac{-5}{2}}\left( -2x+\frac{19}{2} \right)$$

>[!info] The Difference Quotient
>$\frac{f(x+h)-f(x)}{h},h\neq 0$
>
>_First_, solve the first function by replacing it with whatever $(x+h)$ is equal to.
>_Second_, subtract $f(x)$
>Last, divide by $h$

>[!faq]- Solve $f(x)=x^{2}+2x-5$
>Step 1:
>$f(x+h)=(x+h)^{2}+2(x+h)-5$
>$=x^{2}+xh+xh+h^{2}+2x+2h-5$ Distribute
>$x^{2}+2xh+h^{2}+2x+2h-5$
>Step 2:
>$f(x+h)-f(x)=x^{2}+2xh+h{2}+2x+2h-5-(x^{2}+2x-5)$ Cancel out like terms
>$f(x+h)-f(x)=2xh+h^{2}+2h$ Notice that they all have a $h$ which can be factored out
>$2x+h+2$

>[!faq]- Solve $f(x)=\frac{1}{x+1}$
>Step 1:
>$f(x+h)=\frac{1}{x+h+1}$
>Step 2:
>$f(x+h)-f(x)=\frac{1}{x+h+1}-\frac{1}{x+1}$ Notice the denominators ain't the same, so you will need that to continue
>$$=\frac{1(x+1)-1(x+h+1)}{(x+h+1)(x+1)}$$
>Anything times a negative 1 just inverses it's sign
>$\frac{x+1-x-h-1}{(x+h+1)(x+1)}$ Cancel out terms
>$\frac{-h}{(x+h+1(x+1))}$
>Step 3:
>$\frac{-1}{(x+h+1)(x+1)}$

>[!note] Rationalizing the numerator
>In trigonometry you had to rationalize if there was an irrational number in the denominator, such as $\frac{1}{\sqrt{ 3 }}=\frac{\sqrt{ 3 }}{3}$
>
>You'll do the same here with the numerator through the same steps as with the denominator.
>$\frac{\sqrt{ x+h-2 }-\sqrt{ x-2 }}{h}$
>Multiply the denominator and numerator by the numerator.
>$\frac{=x+h-2(x-2)}{h(\sqrt{ x+h-2 }+\sqrt{ x-2 })}$

>[!faq]- $f(x)=x^{3}$
>First:
>	$f(x+h)=(x+h)^{3}$
>	$=(x^{2}+2hx+h^{2})(x+h)$
>	$=x^3+2hx^2+xh^2+hx^2+2h^2x+h^3$ Simplify
>	$=x^3+3hx^2+3h^2x+h^3$
>Now subtract $f(x)$
>	$\frac{h(3x^2+2hx+3h^2)}{h}$
>	$3x^2+3hx+h^2$

>[!faq]- $(x-1)^{-1/2}(x+8^{-1/2}-(x+8)^{1/2}(x-1)^{-1/2}$
>Common factor: $(x-1)^{-1/2}(x+8)^{-1/2}$
>$$(x-1)^{-1/2}(x+8)^{-1/2}\left[ 1-(x+8) \right]$$
>Now simplify
>$(1-x-8)$
>$$(x-1)^{-1/2}(x+8)^{-\frac{1}{2}}(-7-x)$$
>$$-(x-1)^{-1/2}(x+8)^{-\frac{1}{2}}(7+x)$$
>Considering the Difference Quotient $\frac{f(x+h)-f(x)}{h}$
>$f(x)=\frac{7}{x}$
>$f(x+h)=\frac{7}{x+h}$
>$f(x+h)-f(x)=\frac{7}{x+h}-\frac{7}{x}$ Note that the denominators are different, they need to be the same to subtract
>Multiply to get them to be the same
>$$=\frac{7x-7(x+h)}{x(x+h)}$$
>Distribute
>$$\frac{7x-7x-7h}{x(x+h)}$$
>Cancel out like terms
>$$\frac{-7h}{x(x+h)}$$
>$\frac{-7h}{x(x+h)}*\frac{1}{h}$ Now divide by __h__, or easier to multiply by $\frac{1}{h}$ which now you can cross out like terms
>$\frac{-7}{x(x+h)}$

# References

7th edition, _Precalculus_ by Robert Blitzer - Chapter P, Section P.5, Pg 57-88