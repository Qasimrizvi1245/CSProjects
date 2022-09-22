// import java.util.Scanner;

// public class HextoDec {

//     public static int hex2Dec(String HexString){
//     int len = HexString.length();
//     char a = HexString.charAt(0);
//     String sub = HexString.substring(1);

//     if (len == 1){
//         return convertHex(a);
//     }
//     else
//         {
//         int power;
//         int result;
//         power= (int)Math.pow(16,len-1);
//         result = power * convertHex(a) + hex2Dec(sub);
//         return result;
//     }
//   }
//     public static int convertHex(char ch){
//         if (ch - '0' < 10){
//             return ch - '0';
//     }
//     char ch_upper;
//     ch_upper = Character.toUpperCase(ch);
//     return ch_upper - 'A' + 10;

//     }
//     public static void main(String[] args){

//     Scanner scan = new Scanner(System.in);
//     System.out.print("Please Enter hexadecimal number: ");
//     String HexString = scan.nextLine();
//     System.out.println(HexString + " = " + hex2Dec(HexString));

//     }
// }

import java.util.Scanner;
public class HextoDec
{
    public static int hex2Dec(String Num_Hex)
    {
        int len = Num_Hex.length();
        char a = Num_Hex.charAt(0);
        String sub = Num_Hex.substring(1);
        if (len == 1){
            return convertHex(a);
        }
        else{
            int pow;
            int result;
            pow = (int)Math.pow(16,len-1);
            result = pow * convertHex(a) + hex2Dec(sub);
            return result;
        }
    }
    public static int convertHex(char ch)
    {
        System.out.println(ch + " Text " + (ch - 10));
        if (ch - '0' < 10)
        {
            return ch - '0';
        }
        char ch_upper;
        ch_upper = Character.toUpperCase(ch);
        return ch_upper - 'A' + 10;
    }
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter hexadecimal num: ");
        String Num_Hex = in.nextLine();
        System.out.println(Num_Hex + " = " + hex2Dec(Num_Hex));
    }
}
