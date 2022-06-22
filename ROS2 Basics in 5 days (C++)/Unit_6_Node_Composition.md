 What are ROS2 components?

 Components are the equivalent in ROS2 to well-known ROS1 nodelets. By writing our program as a component, we can build it into a shared library instead of an executable. This allows us to load multiple components into a single process. Quite interesting, right?

However, in order to be able to use composition, you need to write your programs in a specific way, as you have already seen in previous units. In order to better understand how composition works, let's follow an example with the programs you created in unit 2.


6.2   Creating a component
