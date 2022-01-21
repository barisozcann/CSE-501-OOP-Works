import java.util.Random;

public class Main {

    public static void main(String[] args){

        Random rand = new Random(); //Random integer generator
        DayofYearSet ds1=new DayofYearSet(); //Using default constructor

        System.out.println("************* Testing Add Method of DayofYearSet class **********************");


        for(int i=0;i<=15;i++)
            ds1.add(new DayofYearSet.DayofYear(rand.nextInt(30)+1,12));

        System.out.println("ds1 class:");
        System.out.println(ds1);

        DayofYearSet ds2=new DayofYearSet(1,12); //Using 2 parameter constructor
        for(int i=0;i<=15;i++)
            ds2.add(new DayofYearSet.DayofYear(rand.nextInt(30)+1,12));
        System.out.println("ds2 class:");
        System.out.println(ds2);

        DayofYearSet ds3=new DayofYearSet();
        for(int i=0;i<=60;i++)
            ds3.add(new DayofYearSet.DayofYear(rand.nextInt(27)+1,rand.nextInt(11)+1));

        System.out.println("ds3 class:");
        System.out.println(ds3);

        DayofYearSet ds4=new DayofYearSet();
        for(int i=0;i<=60;i++)
            ds4.add(new DayofYearSet.DayofYear(rand.nextInt(27)+1,rand.nextInt(11)+1));
        System.out.println("ds4 class:");
        System.out.println(ds4);


        System.out.println("************* Testing Union method of DayofYearSet class **********************");

        System.out.println("Union of ds1 and ds2:");
        System.out.println(ds1.union(ds2));

        System.out.println("Union of ds3 and ds4:");
        System.out.println(ds3.union(ds4));

        System.out.println("************* Testing Intersection method of DayofYearSet class **********************");

        System.out.println("Intersection of ds1 and ds2:");
        System.out.println(ds1.intersection(ds2));

        System.out.println("Intersection of ds3 and ds4:");
        System.out.println(ds3.intersection(ds4));

        System.out.println("************* Testing Difference method of DayofYearSet class **********************");

        System.out.println("Difference of ds1 and ds2 (ds1/ds2):");
        System.out.println(ds1.difference(ds2));

        System.out.println("Difference of ds3 and ds4 (ds3/ds4):");
        System.out.println(ds3.difference(ds4));


        System.out.println("************* Testing Complement method of DayofYearSet class **********************");

        System.out.println("ds1:");
        System.out.println(ds1);
        System.out.println("Complement of ds1:");
        System.out.println(ds1.complement());

        System.out.println("ds2:");
        System.out.println(ds2);
        System.out.println("Complement of ds2:");
        System.out.println(ds2.complement());

        System.out.println("************* Testing size method of DayofYearSet class **********************");

        System.out.println("ds1 Size:"+ds1.size());

        System.out.println("ds2 Size:"+ds2.size());

        System.out.println("ds3 Size:"+ds3.size());

        System.out.println("ds4 Size:"+ds4.size());


        System.out.println("************* Testing remove method of DayofYearSet class **********************");
        System.out.println("ds1: "+ds1);
        for(int i=0;i<=15;i++)
            ds1.remove(new DayofYearSet.DayofYear(rand.nextInt(30)+1,12));

        System.out.println("new ds1 class:");
        System.out.println(ds1);


        System.out.println("ds2: "+ds2);
        for(int i=0;i<=15;i++)
            ds2.remove(new DayofYearSet.DayofYear(rand.nextInt(30)+1,12));

        System.out.println("new ds2 class:");
        System.out.println(ds2);


        System.out.println("************* Testing de Morgan Rules **********************");
        System.out.println("!(ds1 + ds2) == !ds1 ^ !ds2");

        System.out.println("ds1:"+ds1);

        System.out.println("ds2:"+ds2);

        System.out.println("!(ds1 + ds2):"+ds1.union(ds2).complement());

        System.out.println("!ds1 ^ !ds2:"+ds1.complement().intersection(ds2.complement()));


        boolean result1=ds1.union(ds2).complement().equals(ds1.complement().intersection(ds2.complement()));
        System.out.println("Result: "+result1);



        System.out.println("!(ds3 + ds4) == !ds3 ^ !ds4");

        System.out.println("ds3:"+ds3);

        System.out.println("ds4:"+ds4);

        System.out.println("!(ds3 + ds4):"+ds3.union(ds4).complement());

        System.out.println("!ds3 ^ !ds4:"+ds3.complement().intersection(ds4.complement()));


        boolean result2=ds3.union(ds4).complement().equals(ds3.complement().intersection(ds4.complement()));
        System.out.println("Result: "+result2);



        System.out.println("************** All tests are ended ******************");







    }
}
