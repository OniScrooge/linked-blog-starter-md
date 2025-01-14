# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 9.2 Defining Classes for Objects]]

Next - [[COSC Chapter 9.4 Constructors]]
# Content
## Key Point
Classes are definitions for objects and objects are created from classes.

**CodeAnimation 9.1** is a program that demonstrates classes and objects. It constructs three circle objects with radius `1.0`, `25`, and `125` and displays the radius and area of each. Change the radius of the second [[object]] to `100` and display its new radius and area.

## **LiveExample 9.1 TestCircle.cpp**
```cpp
#include <iostream>
using namespace std;

class Circle
{
public:
  // The radius of this circle
  double radius;

  // Construct a default circle object
  Circle()
  {
    radius = 1;
  }

  // Construct a circle object
  Circle(double newRadius)
  {
    radius = newRadius;
  }

  // Return the area of this circle
  double getArea()
  {
    return radius * radius * 3.14159;
  }

  // Return the perimeter of this circle 
  double getPermeter()
  {
    return 2 * radius * 3.14159;
  }

  // Set new radius for this circle 
  void setRadius(double newRadius)
  {
    radius = newRadius;
  }
}; // Must place a semicolon here

int main()
{
  Circle circle1; // No-arg constructor for circle1
  Circle circle2(25); // Create circle2 with radius 25
  Circle circle3(125); // Create circle2 with radius 125

  cout << "The area of the circle of radius "
    << circle1.radius << " is " << circle1.getArea() << endl;
  cout << "The area of the circle of radius "
    << circle2.radius << " is " << circle2.getArea() << endl;
  cout << "The area of the circle of radius "
    << circle3.radius << " is " << circle3.getArea() << endl;

  // Modify circle radius
  circle2.radius = 100;
  cout << "The area of the circle of radius "
    << circle2.radius << " is " << circle2.getArea() << endl;

  return 0;
}
```
```
command>cl TestCircle.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestCircle 
The area of the circle of radius 1 is 3.14159
The area of the circle of radius 25 is 1963.49
The area of the circle of radius 125 is 49087.3
The area of the circle of radius 100 is 31415.9

command>
```

The [[class]] is defined in lines 4–39. Don’t forget that the semicolon (`;`) in line 39 is required.

The [[public]] keyword in line 6 denotes that all [[data fields]], constructors, and functions can be accessed from the objects of the [[class]]. If you don't use the `public` keyword, the visibility is [[private]] by default. [[Private]] visibility will be introduced in ​​**Section​ ​9.8**​, “[[Data Field Encapsulation]].”.​

The main [[function]] creates three objects named `circle1`, `circle2`, and `circle3` with radius `1.0`, `25`, and `125`, respectively (lines 43–45). These objects have different radii but the same functions. Therefore, you can compute their respective areas by using the `getArea()` [[function]]. The [[data fields]] can be accessed via the [[object]] using `circle1.radius`, `circle2.radius`, and `circle3.radius`, respectively. The functions are invoked using `circle1.getArea()`, `circle2.getArea()`, and `circle3.getArea()`, respectively.

These three objects are independent. The radius of `circle2` is changed to `100` in line 55. The [[object]]’s new radius and area are displayed in lines 56–57.

​​​​​As another example, consider TV sets. Each TV is an [[object]] with [[state]] (current channel, current volume level, power on or off) and behaviors (change channels, adjust volume, turn on/off). You can use a [[class]] to model TV sets. The UML diagram for the [[class]] is shown in **Figure ​9.4​**.​

## Figure 9.4
![[Pasted image 20241207114334.png]]

**LiveExample​ 9.2** gives a program that defines the `TV` [[class]] and uses the `TV` [[class]] to create two objects.

## **LiveExample 9.2 TV.cpp**
```cpp
#include <iostream>
using namespace std;

class TV
{
public:
  int channel;
  int volumeLevel; // Default volume level is 1
  bool on; // By default TV is off

  TV()
  {
    channel = 1; // Default channel is 1
    volumeLevel = 1; // Default volume level is 1
    on = false; // By default TV is off
  }

  void turnOn()
  {
    on = true;
  }

  void turnOff()
  {
    on = false;
  }

  void setChannel(int newChannel)
  {
    if (on && newChannel >= 1 && newChannel <= 120)
      channel = newChannel;
  }

  void setVolume(int newVolumeLevel)
  {
    if (on && newVolumeLevel >= 1 && newVolumeLevel <= 7)
      volumeLevel = newVolumeLevel;
  }

  void channelUp()
  {
    if (on && channel < 120)
      channel++;
  }

  void channelDown()
  {
    if (on && channel > 1)
      channel--;
  }

  void volumeUp()
  {
    if (on && volumeLevel < 7)
      volumeLevel++;
  }

  void volumeDown()
  {
    if (on && volumeLevel > 1)
      volumeLevel--;
  }
};

int main()
{
  TV tv1;
  tv1.turnOn(); // Turn tv1 on
  tv1.setChannel(30);
  tv1.setVolume(3);

  TV tv2;
  tv2.turnOn();
  tv2.channelUp();
  tv2.channelUp();
  tv2.volumeUp(); // Increase tv2 volume up 1 level

  cout << "tv1's channel is " << tv1.channel
    << " and volume level is " << tv1.volumeLevel << endl;
  cout << "tv2's channel is " << tv2.channel
    << " and volume level is " << tv2.volumeLevel << endl;

  return 0;
}
```
```
command>cl TV.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TV 
tv1's channel is 30 and volume level is 3
tv2's channel is 3 and volume level is 2

command>
```

Note that the channel and volume level are not changed if the TV is not on. Before changing a channel or volume level, the current values are checked to ensure that the channel and volume level are within the correct range.

The program creates two objects in lines 67 and 72, and invokes the functions on the objects to perform actions for setting channels and volume levels and for increasing channels and volumes. The program displays the [[state]] of the objects in lines 78–81. The functions are invoked using a syntax such as `tv1.turnOn()` (line 68). The [[data fields]] are accessed using a syntax such as `tv1.channel` (line 78).

​​​These examples have given you a glimpse of classes and objects. You may have many questions about constructors and objects, accessing [[data fields]] and invoking objects’ functions. The sections that follow discuss these issues in detail.​

## Self-Check
### Describe the relationship between an [[object]] and its defining [[class]]. How do you define a [[class]]? How do you declare an [[object]]?
You declare an [[object]] from a [[class]]. A [[class]] is like a blueprint for objects. A [[class]] defines a type. You define a [[class]] using the keyword [[class]] followed by a [[class]] name. The [[class]] contains the constructors, functions, and [[data fields]]. To declare an [[object]] is to create an [[object]] using a constructor.
# References
