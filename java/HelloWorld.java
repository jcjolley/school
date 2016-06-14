//Author: Joshua Jolley
//Summary: A simple hello world program.
//Date: 5-14-2014

/**
* Class HelloWorld
* This class simply prints "Hello World!" to the console
*/
public class HelloWorld {

  /**
  * Method sayHello
  * prints "Hello World!" to the console
  */
  public void sayHello() {

    System.out.println("Hello GitHub!");
    System.out.println("Testing...");
  }

  /**
  * Method main
  * Our driver method!  I prefer a gentle, law abiding method of driving.
  */
  public static void main(String args[]) {
    HelloWorld hw = new HelloWorld();
    hw.sayHello();
  }
}