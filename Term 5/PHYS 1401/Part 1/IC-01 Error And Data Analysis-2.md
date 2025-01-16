# IC-01: Error and Data Analysis

Rev: 1-27-2023

## Objective

To study the concept of significant figures, to calculate errors in measurements, and draw graphs.

## 1.1 Introduction

Our knowledge of the physical world around us is obtained from empirical observations and careful laboratory experiments in which we do measurements of physical quantities. It is important to understand how to express data collected from such measurements and how to analyze and draw meaningful conclusions from it. In this introductory study experiment we examine the type of experimental errors and some methods of error and data analysis that will be used in any experiment in which measurements are actually made.

## 1.2 Equipment

Pencil/pen and ruler

Sheets of graph paper

Calculator / computer with some graphing software (excel will do the job well).

## 1.3 Theory

### 1.3.1 Significant Figures

Consider the example: If you measure the length of the red rectangle by placing it next to the scale as shown here, what can be the best, or most accurate, measurement of its length that is a reasonable representation of its actual length.

![C:\Users\khalid.bukhari\OneDrive - Houston Community College\course material\drawings\Labs-phys 1\ruler.png](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/CUserskhalidbukhariOneDrive - Houston Community Collegecourse materialdrawingsLabs-phys 1rulerpng.png>)  
a. 1.8 cm

b. 1.84 cm

c. 1.85 cm

d. 1.846 cm

We can see that the edge of the rectangle is somewhere between 1.8 and 1.9 cm. We can estimate to one digit in between the two marks, i.e. to either 1.84 cm or 1.85 cm, but not to 1.846 cm. Similarly, if we think that 1.84 cm is the length, we must not write it as 1.840 cm, since that would be assuming that we are sure that the third place of decimal is a zero. The number of **meaningful** digits that we write is the number of significant figures.

The significant figures of a (measured or calculated) quantity are the meaningful digits in it. There are conventions which you should learn and follow for how to express numbers so as to properly indicate their significant figures.

- Any digit that is not zero is significant. Thus 459 has three significant figures and 1.961 has four significant figures.
- Zeros between non-zero digits are significant. Thus 2006 has four significant figures.
- Zeros to the left of the first non-zero digit are not significant. Thus 0.000074 has only two significant figures. This is more easily seen if it is written in a scientific notation, i.e., .
- For numbers with decimal points, zeros to the right of a non-zero digit are significant. Thus 3.00 has three significant figures and 0.090 has two significant figures. For this reason, it is important to keep the trailing zeros to indicate the actual number of significant figures.
- For numbers without decimal points, trailing zeros may or may not be significant. Thus, 400 indicates either one, two or three significant figures. It is ambiguous. Scientific notation can be used to remove this ambiguity, so 4×102 has one, 40×101 has 2 and 4.00×103 has three significant figures, respectively. To indicate that the trailing zeros are significant a decimal point must be added. For example, 400. has three significant figures.
- Exact numbers have an infinite number of significant digits. For example, if there are two oranges on a table, then the number of oranges is 2.000... . Defined numbers are also like this. For example, the number of centimeters per inch (2.54) has an infinite number of significant digits, as does the speed of light (299792458 m/s).

There are also specific rules for how to consistently express the uncertainty associated with a number.

- In general, the last significant figure in any result should be of the same order of magnitude (i.e. in the same decimal position) as the uncertainty.
- The uncertainty should be rounded to one or two significant figures.
- Always work out the uncertainty after finding the number of significant figures for the actual measurement.

#### Example 1:

9.82 ± 0.02 10.0 ± 1.5 4 ± 1

The following table shows a few examples of correct and in-correct ways of writing the errors.

|   |   |
|---|---|
|Wrong|Correct|
|9.81 ± 0.02671|9.81 ± 0.03|
|10.0 ± 2|10.0 ± 2.0|
|7 ± 0.2|7.0 ± 0.2|

In practice, when doing mathematical calculations, it is a good idea to keep more digits than are significant to reduce rounding errors. But in the end, the answer must be expressed with only the proper number of significant figures.

After addition or subtraction, the result is significant only to the **place** determined by the largest last significant place in the original numbers. For example,

89.332 + 1.1 = 90.432

should be rounded to get 90.4 (the tenths place is the last significant place in 1.1).

After multiplication or division, the **number** of significant figures in the result is determined by the original number with the smallest number of significant figures. For example,

(2.80) (4.5039) = 12.61092

should be rounded off to 12.6 (three significant figures like that of 2.80).

Sometimes we place a bar over, or underline the last significant digit. This can help to determine the significant digits while doing lengthy calculations, e.g.:

3.52 + 4.7×3.82 = 3.52 + 17.954 (because 4.7 has 2 significant figures, and it is multiplied by 3.82, so the result has 2 significant figures).

3.52 + 17.954 = 21.474 (since we are now adding, the number of decimal places is used. The first number has 2 decimal places, but the second has none, since it is significant to the “7” in the 17.954).

21.474 = 21 is the answer to the correct number of significant figures.

You can use the following link to do significant figure calculations:

[https://www.omnicalculator.com/math/sig-fig](https://www.omnicalculator.com/math/sig-fig)

### 1.3.2 The Idea of Error

#### i. What is meant by "error"?

A measurement may be made of a quantity which has an accepted value which can be looked up in a handbook (e.g. density of copper). The difference between the measurement and the accepted value is **not** what is meant by error. Such accepted values in the books are not "right" answers. They are just measurements made by other people which have errors associated with them as well.

Nor does error mean "blunder". Reading a scale backwards, misunderstanding what we are doing, making calculation mistakes, or walloping into a partner's measuring apparatus are blunders which can be caught and should simply be disregarded.

Obviously, it cannot be determined exactly how far off a measurement is; if this could be done, it would be possible to just give a more accurate, corrected value.

Error, then, has to do with uncertainty in measurements that nothing can be done about. If a measurement is repeated, the values obtained will differ and none of the results can be preferred over the others. Although it is not possible to do anything about such error, it can be characterized. For instance, the repeated measurements may cluster tightly together or they may spread widely. This pattern can be analyzed systematically.

_(Note: Rounding errors and calculation errors are NOT experimental errors)_

#### ii. Classification of Errors

Generally, errors can be divided into two broad and rough but useful classes: s_ystematic_ and _random_.

**_Systematic errors_** are errors which tend to shift all measurements in a systematic way so their mean value is displaced. This may be due to such things as incorrect calibration of equipment, consistently improper use of equipment or failure to properly account for some effect. In a sense, a systematic error is rather like a blunder and large systematic errors can and must be eliminated in a good experiment. But small systematic errors will always be present. For instance, no instrument can ever be calibrated perfectly.

Other sources of systematic errors are external effects which can change the results of the experiment, but for which the corrections are not well known. In science, the reasons why several independent confirmations of experimental results are often required (especially using different techniques) is because different apparatus at different places may be affected by different systematic effects. Aside from making mistakes (such as thinking one is using the ×10 scale, and actually using the ×100 scale), the reason why experiments sometimes yield results which may be far outside the quoted errors is because of systematic effects which were not accounted for.

**_Random errors_** are errors which fluctuate from one measurement to the next. They yield results distributed about some mean value. They can occur for a variety of reasons.

- They may occur due to lack of sensitivity. For a sufficiently a small change an instrument may not be able to respond to it or to indicate it or the observer may not be able to discern it.
- They may occur due to noise. There may be extraneous disturbances which cannot be considered.
- They may be due to imprecise definition.
- They may also occur due to statistical processes such as the roll of dice.

Random errors displace measurements in an arbitrary direction whereas systematic errors displace measurements in a single direction. Some systematic error can be substantially eliminated (or properly taken into account). Random errors are unavoidable and must be lived with.

Many times, you will find results quoted with two errors. The first error quoted is usually the random error, and the second is called the systematic error. If only one error is quoted, then the errors from all sources are added together.

### 1.3.3 Expressing Experimental Error and Uncertainty

#### i. Percent Error

The purpose of some experiments is to determine the value of a well-known physical quantity, for instance the value g-acceleration due to gravity. The accepted or theoretical value of such a quantity is found in textbooks and physics handbooks is the most accurate value obtained through sophisticated experimental methods or mathematical methods.

The absolute difference between the experimental value _XE_ and the theoretical value _XT_ of a physical quantity _X_ is given by the relation:

_Absolute difference_ = _|XE-XT|._

Note that absolute difference is a positive quantity. The fractional error is given by

(1)

In most cases fractional difference is used to calculate percent error which is given by

(2)

#### ii. Percent Difference

It is not always possible to find theoretical value for a physical quantity to be measured. In such circumstance we resort to comparison of results obtained from two equally dependable measurements. The comparison is expressed as a percent difference which is given by

_Percent difference_ = ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment.png>) = ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 1.png>), (3)

where _X1_ and _X2_ are results from the two methods.

#### Example 2:

The established value of the density of aluminum is 2.70 g/cm3. A single measurement of density gives a value of 2.65 g/cm3. Then ρT = 2.70 and ρE = 2.65.

Absolute Difference = _|XE_ – _XT|_ = |2.65 – 2.70| = 0.05 g/cm3.

Fractional Error =

Percent Error = ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 2.png>)×100% = ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 3.png>) = 0.0185 × 100 = 1.85% = 2%

If we had taken several measurements, then the experimental value ρE that we use will be the Mean Value of all the experimental values.

#### Example 3:

The density of aluminum is now found be a different method and come to 2.72 g/cm3. The percent difference between the two measurements is:

Percent Difference =

### 1.3.4 Statistical Tools

#### i. Accuracy and precision

As discussed above, in most cases we do not know what the _real_ value of the measured quantity is. If the measurement is repeated a number of times, we might find that the result is a little different each time, however, not in a systematic or predictable way. These variations in the result are due to _random_ or _statistical errors_. Often the sources of random errors cannot be identified, and random errors cannot be predicted. Thus, it is necessary to quantify random errors by means of statistical analysis. Simply by repeating an experiment or a measurement several times we will get an idea of how much the results vary from one measurement to the other.

**_Accuracy_**: How close the average of the measurements is to the “correct” value.

**_Precision_**: How close the individual measurements are to each other (i.e. how much dispersion is there in the data).

A way to visualize _accuracy_ and _precision_ is by the example of a dart board. If we are a poor "dartist" our shots may be all over the board – and the wall; each shot hitting quite some distance from the other: both our accuracy (i.e. how close we are to the bull’s eye) and our precision (i.e. the scatter of our shots) are low (Fig. 1a).

![C:\Users\khalid.bukhari\OneDrive - Houston Community College\course material\drawings\accuracy and precision.png](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/CUserskhalidbukhariOneDrive - Houston Community Collegecourse materialdrawingsaccuracy and precisionpng.png>)

A somewhat better “dartist” will at least consistently hit the board, but still with a wide scatter: now the accuracy of the throw is high, but the precision remains low (Fig. 1b). Once the player gets consistent and there is not much scatter in the shots, the results may look like Fig. 1c or Fig. 1d.

The results of Fig. 1c are not very accurate (since the average is far from the center), however, the shots have high precision (since they are close to each other); once this is worked out systematically "drift to the right" the shots will be very accurate and very precise (Fig. 1d).

What should be used to quantify the random error of a measurement? If only a single measurement _X_ is made, we must decide how closely we can estimate the digit beyond those which can be read directly, perhaps 0.2 to 0.5 of the distance between the finest divisions on the measuring instrument.

#### Mean Value

Suppose an experiment were repeated many, say N, times to get N measurements of the same quantity, _X_, say _X1, X2, …, XN_. The average or mean value, ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 4.png>)of this measurement is given by

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 5.png>)![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 6.png>)

(4)  
If the data (i.e. experimental values) are accurate to ‘P’ places of decimal, then the Mean Value is also accurate to ‘P’ places of decimal. Taking more data does not increase the decimal places of the mean value.

#### Deviation from the mean

Deviation from the mean or simply, deviation, is a quantitative description of how close the individual measurements are to each other (see e.g. the figures in the section on _Accuracy and Precision_) and is given by

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 7.png>). (5)

Note that the deviation can be positive or negative as some of the measured values are larger than the mean and others smaller. In ideal case the average of the deviations of a set of measurements is zero. As a result, the mean of the deviations, ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 8.png>), is not a useful quantity to describe the dispersion. To obtain the **_average deviation from the mean_**, or _mean deviation_ of set of N measurements, the absolute value of individual deviations has to be calculated, i.e.,

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 9.png>) ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 10.png>) (6)

This is a measure of the dispersion of our data about the mean (i.e. a measure of precision). The experimental value _Xv_ of a measured quantity is given in the form

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 11.png>) (7)

Note that the term ± gives a measure of the precision of the experimental value. The accuracy of the mean value experimental measurements should be expressed in terms of the percent error or percent difference.

#### Example 4:

The following five results were obtained for measured values of density of Aluminum (in g/cm3):

2.62 2.74 2.83 2.67 2.78

k Xk dk |dk|

1 2.62 -0.11 0.11

2 2.74 0.01 0.01

3 2.83 0.10 0.10

4 2.67 -0.06 0.06

5 2.78 0.05 0.05

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 12.png>)=2.728 ∑= -0.01 ∑= 0.33

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 13.png>)=2.73 Average deviation from the mean = 0.33/5 = 0.066

Result: 2.73 ± 0.07 g/cm3

Taking more data with the same instrument should not substantially change the value of deviation.

#### Standard Deviation

From statistical analysis we find that, for a data to have a Gaussian distribution means that the probability of obtaining the result _X_ is,

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 14.png>)![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 15.png>)

(8).  
where _X0_ is most probable value. σ is called the standard deviation and it determines the width of the distribution curve. Because of the law of large numbers this assumption will tend to be valid for random errors. It is a common practice to quote error in terms of the standard deviation of a Gaussian distribution fit to the observed data distribution. This is the way we should quote error in our reports.

The mean is the most probable value of a Gaussian distribution. In terms of the mean, the **standard deviation** of any distribution is,

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 16.png>)

(9)

The quantity σ2, the square of the standard deviation, is called the **variance**. The best estimate of the **true standard deviation** is,

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 17.png>). (10)

The reason why we divide by N to get the best estimate of the mean and only by N-1 for the best estimate of the standard deviation needs to be explained. The true mean value of x is not being used to calculate the variance, but only the average of the measurements as the best estimate of it. Thus, as calculated is always a little bit smaller than

, the quantity really wanted. In the theory of probability (that is, using the assumption that the data has a Gaussian distribution), it can be shown that this underestimate is corrected by using **N-1** instead of **N**. Now we can express the experimental value _Xv_ as

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 18.png>)![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 19.png>) (11)

If one made one more measurement of **x** then (this is also a property of a Gaussian distribution) it would have some 68% probability of lying within![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 20.png>). Note that this means that about 30% of all experiments will disagree with the accepted value by more than one standard deviation!

However, we are also interested in the **standard error of the mean**, which is smaller than σx if there were several measurements. An exact calculation yield,

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 21.png>)

(12)  
for the **standard error of the mean (SE)**. This means that, for example, if there were 20 measurements, the error on the mean itself would be = √20 = 4.47 times smaller than the error of each measurement. The number to report for this series of **N** measurements of x is where . The meaning of this is that if the **N** measurements of **x** were repeated there would be a 68% probability that the new mean value of would lie within (that is between and ). Note that this also means that there is a 32% probability that it will fall outside of this range. This means that out of 100 experiments of this type, on the average, 32 experiments will obtain a value which is outside the standard errors.

For a Gaussian distribution there is a 5% probability that the true value is outside of the range , i.e. twice the standard error, and only a 0.3% chance that it is outside the

range of .

#### v. Propagation of Errors

Frequently, the result of an experiment will not be measured directly. Rather, it will be calculated from several measured physical quantities (each of which has a mean value and an error). What is the resulting error in the final result of such an experiment?

For instance, what is the error in **Z = A + B** where **A** and **B** are two measured quantities with errors ΔA and ΔB respectively?

A first thought might be that the error in **Z** would be just the sum of the errors in **A** and **B**. After all,

 **![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 22.png>)**(13)

and **![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 23.png>)**. (14)

But this assumes that, when combined, the errors in **A** and **B** have the same sign and maximum magnitude; that is that they always combine in the worst possible way. This could only happen if the errors in the two variables were perfectly correlated, (i.e. if the two variables were not really independent).

If the variables are independent then sometimes the error in one variable will happen to cancel out some of the error in the other therefore, on the average, the error in **Z** will be less than the sum of the errors in its parts. A reasonable way to try to take this into account is to treat the perturbations in **Z** produced by perturbations in its parts as if they were "perpendicular" and added according to the Pythagorean Theorem,

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 24.png>). (15)

That is, if **A** = (100 ± 3) and **B** = (6 ± 4) then **Z** = (106 ± 5) since![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 25.png>).

The derivation of the general rule for error propagation is beyond the scope of this course. However, we give results for some common relationships (functional dependences) between measured quantities. Suppose there are two measurements, A and B, and the final result is **Z = F(**A,B**)** for some function **F**.

Relation between _Z_ and (_A,B_) Relation between errors Δ_Z_ and _(_Δ_A,_ Δ_B_)

_1. Z = A± B ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 26.png>)_ 

_2. Z = AB or A/B ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 27.png>)_ 

_3. Z = An ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 28.png>)_ 

_4. Z = ln A ![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 29.png>)_ 

_5. Z = eA_

#### NOTE: As a general rule, when you write your Lab Reports, write all your final answers to 3 significant figures (but not < 2 and not > 4), and all of your percent errors to 1 or 2 significant figures (but not >2).

## 1.4 Graphical Representation of Data

Experimental data is often presented in graphical form for reporting as well as obtain some information easily from properties of the graph.

### 1.4.1 Graphing procedures

In most cases quantities are plotted using Cartesian coordinate system in which the horizontal axis, referred to as abscissa, is labeled as _x_-axis and the vertical axis often called ordinate is labeled as _y_. The location of a point on the graph is specified by its coordinates _x_ and _y_, given as (_x, y_) with respect to the origin, the intersection of the axes.

When plotting data, choose axes scales that are easy to plot and read. In general graphs should have (see Figure 2)

1. Each axis is labeled with the quantity plotted.
2. The units of the quantities plotted.
3. The title of the graph on the graph paper.
4. The tick marks on the axes, with larger ones after bigger intervals.
5. The data points.
6. The best fit line to the data

Why do we plot a data? The main reason for plotting a data in laboratory report is to explore the relationship between various measured quantities. Some quantities of interest in this case are

1. Slope of the graph if the relationship is linear.
2. The degree of the polynomial or the coefficient of the highest degree polynomial for non-linear relationship among measured quantities.

### 1.4.2 Linear Least Square Fit

Even if the theory predicts a linear relationship, there are experimental and statistical errors associated with the data and thus all of the data points will not fall on a straight line if the appropriate variables are plotted. As an example, some experimental data is plotted in Fig. 1. It is evident that no single straight line can pass through all points. By basing the straight line passing through different sets of points, we will obtain different straight lines with different equations. A common, but erroneous method, is to make a straight line that passes through the largest number of points. This is wrong since certain data, which has been determined with the same care and effort as the other data, is completely ignored. Another misconception is that the straight line must pass through the data points. Due to errors, the experimental data that is obtained may be slightly above or below its **true** location, and hence would not fall on the true equation of the phenomenon.

The straight line that provides the "best fit" to the data points is the so-called least square fit, in which we minimize the sum of the squares of the differences between the actual data and the straight-line prediction, i.e. minimize the value of _Σ(Δyi)2_.

We will assume that there is no error in the values of the independent variable x. If Δyi is the difference in the y direction between the actual data and the straight-line prediction for data point i, then for the ith data point we have

Δyi = yi (actual) - yi (predicted) (16)

We then determine the following sums. The equations can be given a simpler appearance if we denote the summations by different symbols, i.e. if we let

P = Σ xi ; Q = Σ yi

R = Σ xi2 ; S = Σ xi yi

n = no. of data values (17)

Where all summations are between i = 1 to i = n. We then obtain:

mR + bP = S (18)

mP + bn = Q (19)

These two equations are then solved simultaneously to find the values of ‘m’ and ‘b’ to obtain the equation of the best fit line: y = mx + b.

For data that is not expected to fall on a straight line, we can make best fit lines for quadratic, polynomial, exponential equations etc.

#### Example 5:

Fit a straight line to the following data by using the method of least squares:

|   |   |   |   |   |
|---|---|---|---|---|
|x|0|1|2|3|
|y|0|1|1|2|

**Solution**

Assuming there is no error in x, we form the following table and sums:

xi yi xi2 xi yi

0 0 0 0

1 1 1 1

2 1 4 2

3 2 9 6 .

sum: _P_=6 _Q_=4 _R_=14 _S_=9

Equations (18) and (19) for m and b become

14m + 6b = 9

6m + 4b = 4

Solving for m and b gives m=0.6 and b=0.1, and thus the equation for the least square straight line fit to the data is given analytically by

y = 0.6x + 0. 1

and is shown graphically by the solid line in Fig. 2. For this line, Σ(Δyi)2 has the minimum value, and it is considered to be the best fit to the given data.

![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 30.png>)![](<remote-vault/Term 5/PHYS 1401/Files & Images/Attachments/Attachment 31.png>)

Fig. 2

## ADDITIONAL RESOURCES

[Significant figures quiz](http://antoine.frostburg.edu/chem/senese/101/measurement/sigfig-quiz.shtml)

[Determining the number of significant figures](http://science.widener.edu/svb/tutorial/sigfigures.html)

[http://mathworld.wolfram.com/LeastSquaresFitting.html](http://mathworld.wolfram.com/LeastSquaresFitting.html)

[**https://www2.chem21labs.com/labfiles/jhu_significant_figures.pdf**](https://www2.chem21labs.com/labfiles/jhu_significant_figures.pdf)

Significant Figures Calculator: [https://www.omnicalculator.com/math/sig-fig](https://www.omnicalculator.com/math/sig-fig)

## 1.5 In-Class problems: Name:__________________________

Solve the following problem in class and hand in before leaving, or upload in Canvas (as told by your instructor). Show your work on a separate sheet of paper. Also solve the problems in the Canvas assignment for this experiment before the due date.

**Q1)** In an experiment to measure the value of π, the following results are obtained (use theoretical value of π = 3.142):

3.12                     3.10                  3.19                  3.09                  3.10                

a) Calculate the Mean Value. ___________ (2 points)

b) Calculate the percent Error. ___________ (2 points)

c) Calculate the True Standard Deviation. ___________ (4 points)

### EQUATIONS:

**Q2)** One of the equations of one-dimensional motion is: _Y = Yo + V T_, where _Y_ is the position of the object in meters at time _T_ (in seconds), _Yo_ is the initial position of the object in meters (i.e. at time = 0.0), and _V_ is the average velocity during this time in meters per second. Since this is a linear equation, the plot between _Y_ (on the y-axis) and _T_ (in the x-axis) should be a straight line, with the slope being the value of the velocity _V_.

In an experiment, following data has been obtained for position of an abject at different times:

|   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|
|Time (seconds)|_T_|0|1|2|3|4|5|
|Position (meters)|_Y_|0|2.7|3.6|6.4|7.3|9.4|

a) Determine the equation (write as _Y = mT + b_) for the best-fit line from this data, by using the method of least squares. Show your work. (6 points)

Equation: ____________________________

b) Draw a graph of this data by using the scale: on X-axis 5 squares = 1.00 s, on Y-axis 5 squares = 1.00 m. On the graph, clearly label the axes, plot the data points, and draw the straight line representing the equation that you found in part ‘a’. (Note: this best-fit line will not pass through all the data points). (3+3 points)

c) Use the slope of the line to find the velocity. (2 points)

Velocity: ____________

**EQUATIONS for Linear Least Square Fit:**

Use: P=Σ xi Q=Σ yi R=Σ xi2 S=Σ xi yi n = Number of data points

All summations are between i = 1 to i = n. We then obtain:

mR + bP = S (18)

mP + bn = Q (19)

Solve simultaneously to find ‘m’ and ‘b’ to obtain the equation of the best fit line: y=mx+b.