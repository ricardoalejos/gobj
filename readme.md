# GOBJ - Generic Object Library

The purpose of this library is to abstract the essential characteristics of objects used for Object-Oriented Programming:

- attributes, and
- behaviors.

Here, suppose that we can define any class C as the tuple (A, I). "A" is a set of sets {A1, A2, ..., AN} containing the attributes of any object O of class C. And "I" is a set of sets {I1, I2, ..., IM} containing the behaviors that any O of class C can have.

In this library, we implement a unique set which is the union of "A" and "I" while we are still able to identify each one of their members (A1, A2, I1, I2, ..., AN, IM).

Let us talk about the example app "app/greetings". We have defined the class `person` for which A={A1=`person_attr`} and I={I1=`person_ifc`}. Then we created three objects of the class `person`, each of which implements the `person_ifc` differently. The `person_ifc` asks compliance classes to implement the behavior `greet`; and each one of our 3 persons greet in different languages (Spanish, Finnish, and English) - see Listings 1 and 2 -. Explore the code to gain more insights on how it works and use the library to your convenience.

```c
int main() {
    greet(person0);
    greet(person1);
    greet(person2);
    return 0;
}
```

**Listing 1** - The app/greetings application body.

```shell
$ ./bin/app_greetings 
Ricardo says: hola!
Petri says: moi!
Fred says: hello!
```

**Listing 2** - The console output of the app/greetings application.
