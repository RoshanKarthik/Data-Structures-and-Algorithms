class Solution {
    private int countDays(String date){
        int[] daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};

        int month = Integer.parseInt(date.substring(0,2));

        int day = Integer.parseInt(date.substring(3,5));

        int totalDays = day;

        for(int i=0; i<month-1; i++){
            totalDays += daysInMonth[i];
        }

        return totalDays;
    }
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int AliceStart = countDays(arriveAlice);
        int AliceEnd = countDays(leaveAlice);

        int BobStart = countDays(arriveBob);
        int BobEnd = countDays(leaveBob);

        int start = Math.max(AliceStart,BobStart);
        int end = Math.min(AliceEnd,BobEnd);

        if(start > end) return 0;

        return end-start+1;
    }
}