Ankit Garg:
import java.util.*;
import java.lang.*;
import java.io.*;

class FEMA2 {
    public static FastReader s;
    public static PrintWriter out;

    public static void main(String[] args) 
    {
        out = new PrintWriter(new OutputStreamWriter(System.out));
        s=new FastReader();
        int t =s.nextInt();
        while(t-->0) 
        {
            int n = s.nextInt();
            int k = s.nextInt() + 1;
            ArrayList<Pair> arr = new ArrayList<>();
            String str = s.next();
            for (int i = 0; i < n; i++) 
            {
                arr.add(new Pair(String.valueOf(str.charAt(i))));
            }
            ArrayList<Integer> I = new ArrayList<>();
            ArrayList<Integer> M = new ArrayList<>();
            int count = 0;
                HashMap<Integer,Integer> map=new HashMap<>();
                int noOfSheets=0;
                for(int i=0;i<n;i++)
                {
                    if(arr.get(i).s.equals("M"))
                    {
                        map.put(i,noOfSheets);
                        M.add(i);
                    }
                    else if(arr.get(i).s.equals("I"))
                    {
                        map.put(i,noOfSheets);
                        I.add(i);
                    }
                    else if(arr.get(i).s.equals(":"))
                    {
                        noOfSheets++;
                        map.put(i,noOfSheets);
                    }
                    else if(arr.get(i).s.equals("X"))
                    {
                        map.put(i,0);
                        for(int x=0;x<M.size();x++)
                        {
                            if(!arr.get(M.get(x)).status)
                            {
                                continue;
                            }
                            for (int y = 0; y < I.size(); y++) 
                            {
                                if(!arr.get(M.get(x)).status)
                                {
                                    break;
                                }
                                if(!arr.get(I.get(y)).status)
                                {
                                    continue;
                                }
                                int power = k - Math.abs(M.get(x) - I.get(y))-Math.abs(map.get(M.get(x))-map.get(I.get(y)));
                                if (power > 0) 
                                {
                                    arr.get(M.get(x)).status=false;
                                    arr.get(I.get(y)).status=false;
                                    count++;
                                    break;
                                }
                            }
                        }
                        noOfSheets=0;
                        M=new ArrayList<>();
                        I=new ArrayList<>();
                    }
                }
                for(int x=0;x<M.size();x++) 
                {
                    if(!arr.get(M.get(x)).status)
                    {
                        continue;
                    }
                    for (int y = 0; y < I.size(); y++) 
                    {
                        if(!arr.get(M.get(x)).status)
                        {
                            break;
                        }
                        if(!arr.get(I.get(y)).status)
                        {
                            continue;
                        }

                        int power = k - Math.abs(M.get(x) - I.get(y))-Math.abs(map.get(M.get(x))-map.get(I.get(y)));
                        if (power > 0) 
                        {
                            arr.get(M.get(x)).status=false;
                            arr.get(I.get(y)).status=false;
                            count++;
                        }
                    }
                }
                out.println(count);

        }

        out.close();
    }
}

class Pair {
    boolean status;
    String s;
    public Pair(String s){
        this.s=s;
        this.status=true;
    }
}