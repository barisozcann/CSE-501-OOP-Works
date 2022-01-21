import java.util.ArrayList;
import java.util.Objects;


/**
 * DayofYearSet class keeps DayofYear objects in array
 * lastIndex is shows first empty space in array
 * capacity is total size of the array
 */
public class DayofYearSet {
    private DayofYear[] dateSet; //DayofYear array

    private int lastIndex,capacity;

    /**
     * DayofYear inner class
     */
    public static class DayofYear{
        private int day,month;
        public static int totalDYObjects=0;

        /**
         * No parameter constructor of DayofYear object. It stars the date with 1st January
         */
        public DayofYear() {
            this.day=1;
            this.month=1;
            totalDYObjects++;
        }

        /**
         * This constructor initializes DayofYear class with given day and month
         * If input is invalid, it exits the program with exit code 1
         * @param day is day
         * @param month is month
         */
        public DayofYear(int day, int month) {
            if(month==1 && day>0 && day<=31){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }
            else if(month==2 && day>0 && day<=28){
                this.day=day;
                this.month=month;
            }
            else if(month==3 && day>0 && day<=31){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }

            else if(month==4 && day>0 && day<=30){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }

            else if(month==5 && day>0 && day<=31){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }

            else if(month==6 && day>0 && day<=30){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }

            else if(month==7 && day>0 && day<=31){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }

            else if(month==8 && day>0 && day<=31){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }
            else if(month==9 && day>0 && day<=30){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }
            else if(month==10 && day>0 && day<=31){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }
            else if(month==11 && day>0 && day<=30){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }
            else if(month==12 && day>0 && day<=31){
                this.day=day;
                this.month=month;
                totalDYObjects++;
            }

            else{ //Invalid date case
                System.out.println(day+"."+month+" is invalid Date!");
                System.exit(1);
            }

        }

        public int getDay() {
            return day;
        }

        public int getMonth() {
            return month;
        }

        public static int getTotalDYObjects() {
            return totalDYObjects;
        }


        /**
         * This overridden method combines properties of the class and returns them in String object
         * @return string value of DayofYear class
         */
        @Override
        public String toString() {
            return "DayofYear{" +
                    "day=" + day +
                    ", month=" + month +
                    '}';
        }

        /**
         * This overridden equals method returns true if two objects are sharing the same day and the same month
         * @param obj is Object class(Classic Base class of every class)
         * @return true if day and month values are the same
         */
        @Override
        public boolean equals(Object obj) {
            if (obj == this) {
                return true;
            }
            if (obj == null || obj.getClass() != this.getClass()) {
                return false;
            }

            DayofYear otherClass = (DayofYear) obj;
            return (this.day==otherClass.day && this.month==otherClass.month);
        }




    }


    /**
     * No parameter constructor of DayofYearSet class
     * It initializes lastIndex as 0 and capacity as 10
     */
    public DayofYearSet() {
        this.lastIndex=0;
        this.capacity=10;
        this.dateSet=new DayofYear[capacity];
//        this.dateSet[lastIndex]=new DayofYear(1,1);
//        this.lastIndex++;
    }


    /**
     * Arraylist constructor of DayofYearSet
     * It initializes the capacity as 2 times of size of given arraylist
     * Then it copies all DayofYear Objects of given arraylist
     * @param arrayList containe bunch of DayofYear objects
     */
    public DayofYearSet(ArrayList<DayofYear> arrayList) {
        this.capacity=arrayList.size()*2;
        this.lastIndex=0;
        this.dateSet=new DayofYear[capacity];

        while(lastIndex<arrayList.size()){
            dateSet[lastIndex]=arrayList.get(lastIndex);
            lastIndex++;
        }
        
    }

    /**
     * This constructor is nearly same with default constructor.
     * Only difference is, it creates a new DayofYear object by using given day and month.
     * Then it keeps this object in its own DayofYear[] array
     * @param day is day
     * @param month is month
     */
    public DayofYearSet(int day, int month) {
        this.lastIndex=0;
        this.capacity=10;
        this.dateSet=new DayofYear[capacity];
        this.dateSet[this.lastIndex]=new DayofYear(day,month);
        this.lastIndex++;
    }


    /**
     * @return array of DayofYearSet class
     */
    public DayofYear[] getdateSet() {
        return dateSet;
    }

    /**
     * @return lastIndex of this class
     */
    public int getLastIndex() {
        return lastIndex;
    }

    /**
     * @return lastIndex of this class because it is equal to the size at the same time.
     */
    public int size(){
        return getLastIndex();
    }

    /**
     * @return capacity of the DayofYear class
     */
    public int getCapacity() {
        return capacity;
    }


    /**
     * Creates an empty DayofYear array with doubled capacity.
     * Then it copies all value from initial array of DayofYearSet class
     */
    public void resize(){
        this.capacity*=2;
        DayofYear[] tempDateSet=new DayofYear[capacity];
        for(int i=0;i<this.lastIndex;i++)
            tempDateSet[i]=this.dateSet[i];

        this.dateSet=tempDateSet;
    }

    /**
     * @return Arraylist version of DayofYear[] array of this class
     */
    private ArrayList<DayofYear> arrayToList(){
        ArrayList<DayofYear> arrayList=new ArrayList<DayofYear>();
        for(int i=0;i<this.lastIndex;i++)
            arrayList.add(this.dateSet[i]);
        return arrayList;
    }

    /**
     * It first checks if given DayofYear object exists in the class
     * Then, it checks if lastIndex has reached the capacity(If answer is yes, it calls resize() method
     * Finally it adds given DayofYear object to the lastIndex of DayofYear[] array of this class
     * @param dayofYear is given DayofYear object
     */
    public void add(DayofYear dayofYear){
        if(findIndex(dayofYear)!=-1){
            System.out.println("DayofYear Object: "+dayofYear+" is already in the DayofYearSet class");
            System.out.println("DayofYear object is at index: "+findIndex(dayofYear));
            System.out.println("You can't add a duplicate object!");
            return;
        }

        if(lastIndex==capacity)
            resize();

        this.dateSet[lastIndex]=dayofYear;
        lastIndex++;
    }

    /**
     * This method finds index of given DayofYear object in the DayofYear[] array of this class
     * @param dayofYear is given DayofYear object
     * @return index of the given DayofYear object. It returns -1 if the object does not exist in this class
     */
    private int findIndex(DayofYear dayofYear){
        for(int i=0;i<this.lastIndex;i++){
            if(dayofYear!=null && dateSet[i].equals(dayofYear))
                return i;
        }
        return -1;
    }

    /**
     * This method shifts all DayofYear object to the left by starting from the index of removed object
     * @param dayofYear is given DayofYear object
     */
    public void remove(DayofYear dayofYear){
       if(lastIndex==0){
           System.out.println("You can't remove any element because container is empty!");
           return;
       }

       int removeIndex=findIndex(dayofYear);

       if(removeIndex==-1){
          System.out.println("You can't remove "+dayofYear+" because it doesn't exist in the container");
           return;
       }

       DayofYear d1=dateSet[removeIndex];

       while(removeIndex<lastIndex){
           dateSet[removeIndex]=dateSet[removeIndex+1];
           removeIndex++;
       }
       this.lastIndex--;

       System.out.println(d1+ " has removed from the class");
    }


    /**
     * This method compares all objects of array of this class with another DayofYearSet class' array objects
     * @param obj
     * @return if two classes have the same DayofYear objects in its DayofYear[] array
     */
    @Override
    public boolean equals(Object obj) {
        if (obj == this) {
            return true;
        }
        if (obj == null || obj.getClass() != this.getClass()) {
            return false;
        }

        DayofYearSet otherClass = (DayofYearSet) obj;

        for(var dayofyear1: dateSet)
            if(otherClass.findIndex(dayofyear1)==-1 && dayofyear1!=null)
                return false;

        for(var dayofyear2: otherClass.dateSet)
            if(findIndex(dayofyear2)==-1 && dayofyear2!=null)
                return false;

        return true;
    }

    /**
     * @param dayofYearSet
     * @return true if one class have at least one different DayofYear object
     */
    public boolean notEquals(DayofYearSet dayofYearSet){
        return !(this.equals(dayofYearSet));
    }

    /**
     * This class creates an arraylist to store intersection set elements
     * Then It constructs a new DayofYearSet class by giving this arraylist as input parameter
     * @param dayofYearSet
     * @return
     */
    public DayofYearSet intersection(DayofYearSet dayofYearSet){
        ArrayList<DayofYear> dayofYearArrayList=new ArrayList<DayofYear>();
        for(var dayofyear2: dayofYearSet.dateSet)
            if(findIndex(dayofyear2)!=-1)
                dayofYearArrayList.add(dayofyear2);


        dayofYearArrayList.removeIf(Objects::isNull);
        return new DayofYearSet(dayofYearArrayList);
    }

    /**
     * This class creates an arraylist to store difference set elements
     * Then It constructs a new DayofYearSet class by giving this arraylist as input parameter
     * @param dayofYearSet
     * @return
     */
    public DayofYearSet difference(DayofYearSet dayofYearSet){
        ArrayList<DayofYear> dayofYearArrayList=new ArrayList<DayofYear>();
        for(var dayofyear1: dateSet)
            if(dayofYearSet.findIndex(dayofyear1)==-1)
                dayofYearArrayList.add(dayofyear1);

        dayofYearArrayList.removeIf(Objects::isNull);
        return new DayofYearSet(dayofYearArrayList);
    }


    /**
     * This class creates an arraylist to store union set elements
     * Then It constructs a new DayofYearSet class by giving this arraylist as input parameter
     * It combines A/B B/A and AnB
     * @param dayofYearSet
     * @return
     */
    public DayofYearSet union(DayofYearSet dayofYearSet){
        ArrayList<DayofYear> dayofYearArrayList;


        dayofYearArrayList=intersection(dayofYearSet).arrayToList(); //Gets intersection set

        dayofYearArrayList.addAll(difference(dayofYearSet).arrayToList()); //Adds 1st difference set

        dayofYearArrayList.addAll(dayofYearSet.difference(this).arrayToList()); //Adds 2nd difference set

        dayofYearArrayList.removeIf(Objects::isNull);

        return new DayofYearSet(dayofYearArrayList);
    }


    /**
     * This class creates an arraylist to store complement set elements
     * Then It constructs a new DayofYearSet class by giving this arraylist as input parameter
     * @return
     */
    public DayofYearSet complement(){
        ArrayList<DayofYear> dayofYearArrayList=new ArrayList<>();

        DayofYear tempDY;
        int month=1;
        for(int i=1;i<=31;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);
        }

        month=2;
        for(int i=1;i<=28;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);
        }

        month=3;
        for(int i=1;i<=31;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);
        }

        month=4;
        for(int i=1;i<=30;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);
        }

        month=5;
        for(int i=1;i<=31;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);

        }

        month=6;
        for(int i=1;i<=30;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);

        }

        month=7;
        for(int i=1;i<=31;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);
        }

        month=8;
        for(int i=1;i<=31;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);
        }

        month=9;
        for(int i=1;i<=30;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);
        }

        month=10;
        for(int i=1;i<=31;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);
        }

        month=11;
        for(int i=1;i<=30;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);
        }

        month=12;
        for(int i=1;i<=31;i++){
            tempDY=new DayofYear(i,month);
            if(findIndex(tempDY)==-1)
                dayofYearArrayList.add(tempDY);
        }


        dayofYearArrayList.removeIf(Objects::isNull);

        return new DayofYearSet(dayofYearArrayList);
    }


    /**
     * This overridden toString method returns size,lastIndex and array elements of DayofYearSet class
     * @return properties of this class as string value
     */
    @Override
    public String toString() {
        String properties= "DayofYearSet{ " +
                "lastIndex=" + lastIndex +
                ",\t capacity=" + capacity +
                ",\ndateSet=[\n";
        for(int i=0;i<lastIndex;i++)
            if(dateSet[i]!=null)
                properties = properties + (dateSet[i] + ",\n");

        properties=properties+"]\n}";
        return properties;
    }
}
