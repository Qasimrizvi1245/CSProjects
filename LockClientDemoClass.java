import java.util.Scanner;

interface Lock {
    public abstract void setX(int x);
    public abstract void setY(int y);
    public abstract void setZ(int z);
    public abstract void alter(int x, int y, int z);
    public abstract void turn(int TurnX, int TurnY, int TurnZ);
    public void close();
    public void attempt(int xAttempt, int yAttempt, int zAttempt);
    public void inquire();
    public int current();
}

class LockDataStructureClass implements Lock {
    private int KeyX, KeyY, KeyZ;
    private int dial = 0;
    private boolean on;
    private boolean lock = true;
    protected LockDataStructureClass() {
        this(0, 0, 0);
    }
    protected LockDataStructureClass(int x, int y, int z) {
        setX(x);
        setY(y);
        setZ(z);
    }
    protected LockDataStructureClass(LockDataStructureClass lockDSC) {
        this(lockDSC.KeyX, lockDSC.KeyY, lockDSC.KeyZ);
    }
    public void setX(int x) {
        this.KeyX = x;
    }
    public void setY(int y) {
        this.KeyY = y;
    }
    public void setZ(int z) {
        this.KeyZ = z;
    }

    public void alter(int x, int y, int z) {
        setX(x);
        setY(y);
        setZ(z);
    }

    public void turn(int xTurn, int yTurn, int zTurn) {
        on = true;
        System.out.println("No. 1");
        System.out.print("The first number is " + xTurn + " = ");
        for (dial = current(); on; dial--) {
            if (dial == 0) {
                for (dial = 40; dial >= zTurn; dial--) {
                    System.out.print(((dial == 40) ? 0 : dial) + " ");
                }
                for (; on; dial--) {
                    if (dial == 0) {
                        for (dial = 40; dial >= xTurn; dial--) {
                            System.out.print((dial == 40 ? 0 : dial) + " ");
                        }
                        on = false;
                    } else {
                        System.out.print(dial + " ");
                    }
                }
                on = false;
            } else {
                System.out.print(dial + " ");
            }
        }
        on = true;
        System.out.println("\nNo. 2");
        System.out.print("Second number is " + yTurn + " = ");
        for (dial = xTurn; on; dial++) {
            if (dial == 40) {
                for (dial = 0; dial <= xTurn; dial++) {
                    System.out.print(dial + " ");
                }
                for (; on; dial++) {
                    if (dial == 40) {
                        for (dial = 0; dial <= yTurn; dial++) {
                            System.out.print(dial + " ");
                        }
                        on = false;
                    } else {
                        System.out.print(dial + " ");
                    }
                }
                on = false;
            } else {
                System.out.print(dial + " ");
            }
        }
        on = true;
        System.out.println("\nNo. 3");
        System.out.print("Third number is " + zTurn + " = ");
        for (dial = yTurn; on; dial--) {
            if (dial == 0) {
                for (dial = 40; dial >= zTurn; dial--) {
                    System.out.print((dial == 40 ? 0 : dial) + " ");
                }
                on = false;
            } else {
                System.out.print(dial + " ");
            }
        }
        dial++;
        dial++;
    }
    public void close() {
        lock = false;
        System.out.println("The lock is closed");
    }
    public void attempt(int xAttempt, int yAttempt, int zAttempt) {
        turn(xAttempt, yAttempt, zAttempt);
        if ((xAttempt == KeyX) && (yAttempt == KeyY) && (zAttempt == KeyZ)) {
            lock = true;
        }
    }
    public void inquire() {
        if (lock == true) {
            System.out.println("The lock is open");
        } else
            System.out.println("The lock is shut");
    }
    public int current() {
        return dial;
    }
    public String toString() {
        return
                "Please select from the following options: " +
                        "\n1: alter the lock's combination to a new 3-number combination" +
                        "\n2: close the lock" +
                        "\n3: check the status of the lock (open or shut) " +
                        "\n4: attempt to open the lock" +
                        "\n5: check what number is currently on top" +
                        "\n6: exit";
    }
}

public class LockClientDemoClass {
    public static void main(String[] args) {
        Scanner ans = new Scanner(System.in);
        LockDataStructureClass lock1 = new LockDataStructureClass();
        int givenNumber;
        System.out.println(" ");
        System.out.println(lock1.toString());

        givenNumber = ans.nextInt();
        while (givenNumber != 6)
            switch (givenNumber) {
                case 1:
                    System.out.println("Set the lock Combination: ");
                    System.out.println("Enter the first number: ");
                    int firstNumber = ans.nextInt();
                    System.out.println("Enter the second number: ");
                    int secondNumber = ans.nextInt();
                    System.out.println("Enter the third number: ");
                    int thirdNumber = ans.nextInt();
                    System.out.println();
                    lock1.alter(firstNumber, secondNumber, thirdNumber);
                    System.out.println(" ");
                    System.out.println(lock1.toString());

                    givenNumber = ans.nextInt();
                    break;
                case 2:
                    lock1.close();
                    System.out.println(" ");
                    System.out.println(lock1.toString());

                    givenNumber = ans.nextInt();
                    break;
                case 3:
                    lock1.inquire();
                    System.out.println(" ");
                    System.out.println(lock1.toString());

                    givenNumber = ans.nextInt();
                    break;
                case 4:
                    System.out.println("Enter your first number: ");
                    firstNumber = ans.nextInt();
                    System.out.println("Enter your second number: ");
                    secondNumber = ans.nextInt();
                    System.out.println("Enter your third number: ");
                    thirdNumber = ans.nextInt();
                    System.out.println();
                    lock1.attempt(firstNumber, secondNumber, thirdNumber);
                    System.out.println("\n ");
                    System.out.println(lock1.toString());

                    givenNumber = ans.nextInt();
                    break;
                case 5:
                    System.out.println("The number currently on top is " + lock1.current());
                    System.out.println(" ");
                    System.out.println(lock1.toString());

                    givenNumber = ans.nextInt();
                    break;
                default:
                    System.out.println("Wrong Entry Please try again");
                    System.out.println(" ");
                    System.out.println(lock1.toString());

                    givenNumber = ans.nextInt();
            }
    }
}

