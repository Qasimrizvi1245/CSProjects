import java.util.Scanner;
interface StudentsADT
{
    public abstract int getMaxNumOfStudents();
    public abstract void setMaxNumOfStudents(int maxNumOfStudents);
    public abstract void addStudent(int id);
    public abstract void addCourse(int id, Course course);
    public abstract void dropCourse(int id, Course course);
    public abstract String toString();
}
class Course {
    private String name;
    private int section, credits;
    private Course link;
    public Course() {
        this("", 0, 0, null);
    }
    public Course(String name, int section, int credits, Course link) {
        this.name = name.toUpperCase().trim();
        this.section = section;
        this.credits = credits;
        this.link = link;
    }
    public Course(Course obj) {
        this.name = obj.name;
        this.section = obj.section;
        this.credits = obj.credits;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name.toUpperCase().trim();
    }
    public int getSection() {
        return section;
    }
    public void setSection(int section) {
        this.section = section;
    }
    public int getCredit() {
        return credits;
    }
    public void setCredit(int credits) {
        this.credits = credits;
    }
    public Course getLink() {
        return link;
    }
    public void setLink(Course link) {
        this.link = link;
    }
    public String toString() {
        return String.format("%s%s%02d%s", this.name,
                " Section:", this.section,
                " Credits:" + this.credits);
    }
}
class Students implements StudentsADT {
    public static class Student {
        private int id;
        private Course courses;
        public Student() {
            this.id = 0;
            this.courses = null;
        }
        public Student(int id) {
            this.id = id;
            this.courses = null;
        }
        public Course getCourses() {
            return this.courses;
        }
        public int getId() {
            return this.id;
        }
        public void setId(int id) {
            this.id = id;
        }
        public void setCourses(Course courses) {
            Course cur2 = courses,
                    cur3 = this.courses;
            this.courses = cur2;
            while (cur2 != null) {
                cur3.setLink(cur2.getLink());
                cur3 = cur3.getLink();
                cur2 = cur2.getLink();
            }
        }
        public void addCourse(Course course) {
            if (this.courses == null) {
                this.courses = course;
                System.out.println(course.getName() + " successfully added.");
                return;
            }
            Course current = this.getCourses();
            while (current.getLink() != null) {
                current = current.getLink();
            }
            current.setLink(new Course(course));
            System.out.println(course.getName() + " successfully added.");
        }
        public Course dropCourse(Course course) {
            if (this.courses != null) {
                Course current = this.getCourses(),
                        previous = current;
                while (current != null &&
                        !current.getName().equals(course.getName()) &&
                        current.getSection() != course.getSection()) {
                    previous = current;
                    current = current.getLink();
                }
                if (current == null) {
                    System.out.println(course.getName() + " is not registered.");
                    return null;
                } else {
                    if (current == this.courses)
                        this.courses = this.courses.getLink();
                    else
                        previous.setLink(current.getLink());
                    System.out.println("The course " + course.getName() + " has been successfully removed.");
                    return current;
                }
            }
            System.out.println("The course " + course.getName() + " is not registered.");
            return null;
        }
        public String toString() {
            StringBuilder s = new StringBuilder("Student ID# " + this.getId() + "\n");
            if (this.courses != null) {
                Course current = this.courses;
                while (current != null) {
                    s.append(current).append("\n");
                    current = current.getLink();
                }
            }
            else {
                s.append(" No courses have been registered.\n");
            }
            s.append(" ");
            return s.toString();
        }
    }
    private int maxNumOfStudents;
    private final Student[] student;
    public Students() {
        this(10);
    }
    public Students(int maxNumOfStudents) {
        this.maxNumOfStudents = maxNumOfStudents;
        this.student = new Student[maxNumOfStudents];
    }
    public Students(Students obj) {
        this.maxNumOfStudents = obj.getMaxNumOfStudents();
        this.student = new Student[maxNumOfStudents];
        for (int i = 0; (i < maxNumOfStudents && obj.student[i] != null); i++) {
            this.student[i] = obj.student[i];
        }
    }
    public int getMaxNumOfStudents() {
        return maxNumOfStudents;
    }
    public void setMaxNumOfStudents(int maxNumOfStudents) {
        this.maxNumOfStudents = maxNumOfStudents;
    }
    public void addStudent(int id) {
        int i;
        Student obj = new Student(id);
        for (i = 0; (i < maxNumOfStudents && student[i] != null); i++) {
        }
        if (i < maxNumOfStudents) {
            student[i] = obj;
        } else {
            System.err.println("You cannot add new students as there is no space.");
        }
    }
    public void addCourse(int id, Course course) {
        int i = 0;
        while (i < maxNumOfStudents && student[i] != null && student[i].getId() != id) {
            i++;
        }
        if (i < maxNumOfStudents && student[i] != null) {
            student[i].addCourse(course);
        }
        else {
            System.err.println("The entered Student ID#" + id + " Does not exist.\n" +
                    "The course " + course.getName() + " cannot be dropped");
        }
    }
    public void dropCourse(int id, Course course) {
        int i = 0;
        while (i < maxNumOfStudents && student[i] != null && student[i].getId() != id) {
            i++;
        }
        if (i < maxNumOfStudents && student[i] != null) {
            student[i].dropCourse(course);
        }
        else {
            System.err.println("The entered Student ID#" + id + " Does not exist.\n" +
                    "The course " + course.getName() + " cannot be dropped");
        }
    }
    public String toString() {
        int i = 0;
        StringBuilder s = new StringBuilder();
        while (i < maxNumOfStudents && student[i] != null) {
            s.append(student[i++].toString()).append("\n");
        }
        return s.toString();
    }
}
public class StudentsDemo
{
    private static final Scanner key = new Scanner(System.in);
    public static void main(String[] args)
    {
        System.out.println();

        System.out.println("Hello! Welcome to Course Planner");

        System.out.println();

        System.out.println("You can currently change 3 student's Course Planner.");
        System.out.println("The first student's ID is 111, The second student's ID is 1234, The third student's ID is 2357.");

        System.out.println();

        System.out.println("");
        System.out.println("These courses were automatically added.");
        System.out.println("HIS101 successfully added.");

        Students students = new Students(10);
        students.addStudent(1111);
        students.addStudent(1234);
        students.addStudent(2357);
        Course c1 = new Course("CSC236", 4, 3, null);
        Course c2 = new Course("HIS101", 2, 4, null);
        Course c3 = new Course("CSC162", 1, 3, c2);
        students.addCourse(1111, c3);
        students.addCourse(2357, c1);
        function(students);
    }
    private static void display()
    {
        System.out.println("What action would you like to implement?");
        System.out.println("1: Show all Students");
        System.out.println("2: Add a course");
        System.out.println("3: Drop a Course");
        System.out.println("9: Quit");
    }
    private static void function(Students students)
    {
        System.out.println("\n");
        display();
        System.out.print("Please enter your choice: ");
        int choice = key.nextInt();
        System.out.println();
        switch(choice)
        {
            case 1:
                System.out.println(students);
                function(students);
                break;
            case 2:
                System.out.print("Please enter the student ID: ");
                int id = key.nextInt();
                System.out.print("Please enter the course name: ");
                String name = key.next();
                System.out.print("Please enter the course section number: ");
                int sectionNum = key.nextInt();
                System.out.print("Please enter the number of credits of the course: ");
                int credits = key.nextInt();
                students.addCourse(id, new Course(name, sectionNum, credits, null));
                function(students);
                break;
            case 3:
                System.out.print("Please enter the student ID: ");
                id = key.nextInt();
                System.out.print("Please enter the course name: ");
                name = key.next();
                System.out.print("Please enter the section number: ");
                sectionNum = key.nextInt();
                System.out.print("Please enter the number of credits of the course: ");
                credits = key.nextInt();
                students.dropCourse(id, new Course(name, sectionNum, credits, null));
                function(students);
                break;
            case 9:
                System.out.println("Thank you, have a good day");
                System.exit(0);
                break;
            default :
                System.out.println("Invalid choice, please pick from the options above");
                function(students);
                break;
        }
    }
}
