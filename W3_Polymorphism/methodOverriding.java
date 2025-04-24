class Animal {
    void makeSound() {
        System.out.println("Some generic animal sound");
    }
}

class Dog extends Animal {
    @Override
    void makeSound() {
        System.out.println("Woof!");
    }
}

class Cat extends Animal {
    @Override
    void makeSound() {
        System.out.println("Meow!");
    }
}

public class methodOverriding {
    public static void main(String[] args) {
        Animal a;
        a = new Dog();
        a.makeSound();  // Woof!

        a = new Cat();
        a.makeSound();  // Meow!
    }
}