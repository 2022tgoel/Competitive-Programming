import java.io.*;
import java.util.*;

class cowjump {
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("cowjump.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowjump.out")));
    
    int pointNum = Integer.parseInt(f.readLine());
    
    float[][] points = new float [pointNum][4];
    // Use StringTokenizer vs. readLine/split -- lots faster
   for (int i = 0; i<pointNum; i++){
       StringTokenizer st = new StringTokenizer(f.readLine());
   						  // Get line, break into tokens
       points[i][0] = Float.parseFloat(st.nextToken());    // first integer
       points[i][1] = Float.parseFloat(st.nextToken());    // second integer
       points[i][2] = Float.parseFloat(st.nextToken());    
       points[i][3] = Float.parseFloat(st.nextToken());
  }
    for(int j =0; j<pointNum; j++){
      float[] p1 = points[j];
      ArrayList<Integer> inters = new ArrayList<Integer>();
      for (int k = j+1; k<pointNum; k++){
         if(findInter(p1, points[k])){
            inters.add(k);
         }
      }
      if(inters.size() >1){
         out.println(j+1);
         out.close();
         System.exit(0);
      }
      else if (inters.size()==1){
         p1 = points[inters.get(0)];
         ArrayList<Integer> cas = new ArrayList<Integer>();
         for (int l = 0; l<pointNum; l++){
            if(findInter(p1, points[l])){
               
               cas.add(l);
            }
         }
         if(cas.size()>1){
            out.println(inters.get(0)+1);
            out.close();
            System.exit(0);
         }else{
            out.println(j+1);
            out.close();
            System.exit(0);
         }
      }

    } 
     
                               // close the output file
  }
  public static boolean findInter(float[] p1, float[] p2){
      float A1 = p1[3]-p1[1];
      float B1 = p1[0]-p1[2];
      float C1 = (A1*p1[0])+(B1*p1[1]);
      float A2 = p2[3]-p2[1];
      float B2 = p2[0]-p2[2];
      float C2 = A2*p2[0]+B2*p2[1];
      float det = A1*B2 - A2*B1;
      if(det == 0){
         return false;
      }else{
         float x = ((B2*C1) - (B1*C2))/det;
         float y = ((A1*C2) - (A2*C1))/det;
         if (Math.min(p1[0], p1[2])<=x&&x<=Math.max(p1[0], p1[2]) && Math.min(p2[0], p2[2])<=x&&x<=Math.max(p2[0], p2[2]) &&Math.min(p2[1], p2[3])<=y&&y<=Math.max(p2[1], p2[3])&& Math.min(p1[1], p1[3])<=y&&y<=Math.max(p1[1], p1[3]))
      {
         return true;
      }else{
         return false;
      }
      }
      
  }
}