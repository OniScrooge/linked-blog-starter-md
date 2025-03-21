# Formulas
- _Average Angular Speed_ - $\omega=\frac{\theta_{f}-\theta_{i}}{t_{f}-t_{i}}=\frac{\nabla \theta}{\nabla t}$ where $\omega$ is Omega
- _Average Angular Acceleration_ - $\alpha_{av}=\frac{\omega_{f}-\omega_{i}}{t_{f}-t_{i}}=\frac{\nabla \omega}{\nabla t}$
- _Linear Motion with a Constant_:
	- $v=v_{i}+a*t$
	- $\nabla x=v_{i}*t+\frac{1}{2}*a*t^2$
	- $v^2=v_{i}^2+2*a*\nabla x$
- _Rotational Motion About a Fixed Axis with a Constant_
	- $\omega=\omega_{i}+\alpha*t$
	- $\nabla \theta=\omega_{i}*t+\frac{1}{2}*\alpha*t^2$
	- $\omega^2=\omega_{i}^2+2*\alpha*\nabla \theta$
- _Centripetal Acceleration_ - $a_{c}=\frac{v^2}{r}$
- _Centripetal Force(General Equation)_ - $F_{c}=m*a_{c}=\frac{m*v^2}{r}$
- _Level Curves_ - $v=\sqrt{ \mu*r*g }$
- _Banked Curves_ - $\tan \theta=\frac{v^2}{r*g}$ or $a_{c}=g*\tan \theta$
- _Vertical Circle_ - $v_{top}=\sqrt{ g*R }$
- _Newton's Law of Universal Gravitation_ - $F=G*\frac{m_{1}*m_{2}}{r^2}$ where $G=6.673\times10^{-11}Nm^2/kg^2$ is the constant of universal gravitation
- _Gravitational Potential Energy_ - $PE=-G\frac{M_{E}*m}{r}$
- _Escape Speed_ - $v_{esc}=\sqrt{ \frac{2GM_{E}}{R_{E}} }$
- _Kepler's Third Law_:
	- $M_{p}*a_{c}=\frac{M_{p}*v^2}{r}=\frac{G*M_{s}*M_{p}}{r^2}$
	- $v=\frac{2\pi r}{T}\to \frac{M_{p}\left( \frac{2\pi r}{T} \right)^2}{r}=\frac{GM_{s}M_{p}}{r^2}$
	- $T^2=\left( \frac{4\pi^2}{GM_{s}} \right)r^3=K_{s}r^3$
	- $K_{s}=\frac{4\pi^2}{GM_{s}}=2.09\times_{1}0^{-19}s^2/m^3$

# Related

Prev - [[PHYS Chapter 6 - Momentum]]

Next - [[PHYS Chapter 8 - Rotational Equilibrium and Rotational Dynamics]]

# Content
- Rotational motion
	- Motion of the Earth
	- Rotating wheels
- Angular motion
	- Expressed in terms of:
		- Angular speed
		- Angular acceleration
		- Centripetal acceleration
- Angular motion
	- Angular Displacement - $\nabla \theta=\theta_{f}-\theta_{i}$
	- Angular Velocity - $\omega=\frac{\theta_{f}-\theta_{i}}{t_{f}-t_{i}}=\frac{\nabla \theta}{\nabla t}$
		- _Instantaneous angular speed_ is the limit of average speed as time approaches 0.
		- In $rad/s$
		- Speed is + if it moves counter-clockwise
		- If angular speed is constant, so is the instantaneous
	- Angular Acceleration - $\alpha_{av}=\frac{\omega_{f}-\omega_{i}}{t_{f}-t_{i}}=\frac{\nabla \omega}{\nabla t}$
		- $rad/s^2$
		- Counter-clockwise = positive
		- $\lim_{ \nabla x \to 0 }\frac{\nabla \omega}{\nabla t}$
- Radian - Unit of angle measure
	- AKA _arc length_ along a _circle_ divided by _radius_
	- $\theta=\frac{s}{r}$
- Radian to degrees - 1 rad = $\frac{360\degree}{2\pi}=57.3\degree$
- Degrees to radians - $\theta=\frac{\pi}{180\degree}*\theta$
- _Rigid body_ - Means that each part of the body is in a fixed position relative to each other part.
- _Centripetal acceleration_ - Even though it moves with constant speed in a circle, will have constant acceleration.
	- The acceleration is directed toward the center of the circle of motion.
	- Magnitude of _CA_ - $\alpha_{c}=\frac{V^2}{r}$
	- _CA_ & Angular velocity - $\alpha_{c}=\frac{V^2}{r}=\frac{r^2\omega^2}{r}=r\omega^2$
- _Total acceleration_ - Tangential component of acceleration
	- $a=\sqrt{ a_{t}^2+a_{c}^2 }$
	- If you have const tangential velocity $V_{t}$, you have $a=a_{c}$
- Centripetal force
	- General equation - $F_{c}=ma_{c}=\frac{mv^2}{r}$
	- Is not a force itself, and is supplied by some other physical force
- Applications of forces causing _CA_
	- Level curves - Friction is the force
		- $v=\sqrt{ \mu*r*g }$
	- Banked curves - Normal force adds to the frictions force
		- $\tan \theta=\frac{v^2}{r*g}$ or $a_{c}=g\tan \theta$
	- Horizontal circles - 
	- Vertical circles - Minimal speed at the top of a circle can be found
		- $V_{top}=\sqrt{ g*R }$
		- $V_{bot}=\sqrt{ 5*g*R }$
- _Kepler's Laws_:
	-  First - All planets move in elliptical orbits with the Sun at one focus.
	- Second - A line drawn from the Sun to any planet will sweep out equal areas in equal times.
	- Third - The square of the orbital period of any planet is proportional to cube of the average distance from the Sun to the planet.