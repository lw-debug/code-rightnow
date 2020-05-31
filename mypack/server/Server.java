package mypack.server;

import java.io.*;

import java.math.RoundingMode;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.DecimalFormat;


import mypack.test.md5;

 
/**
 * 文件传输Server端<br>
 * 功能说明：
 *
 * @author 大智若愚的小懂
 * @Date 2016年09月01日
 * @version 1.0
 */
public class Server extends ServerSocket {
 
    private static final int SERVER_PORT = 8899; // 服务端端口
 
    private static DecimalFormat df = null;
 
    static {
        // 设置数字格式，保留一位有效小数
        df = new DecimalFormat("#0.0");
        df.setRoundingMode(RoundingMode.HALF_UP);
        df.setMinimumFractionDigits(1);
        df.setMaximumFractionDigits(1);
    }
 
    public Server() throws Exception {
        super(SERVER_PORT);
    }
 
    /**
     * 使用线程处理每个客户端传输的文件
     * @throws Exception
     */
    public void load() throws Exception {
        while (true) {
            // server尝试接收其他Socket的连接请求，server的accept方法是阻塞式的
            final Socket socket = this.accept();
            /**
             * 我们的服务端处理客户端的连接请求是同步进行的， 每次接收到来自客户端的连接请求后， 都要先跟当前的客户端通信完之后才能再处理下一个连接请求。
             * 这在并发比较多的情况下会严重影响程序的性能， 为此，我们可以把它改为如下这种异步处理与客户端通信的方式
             */
            // 每接收到一个Socket就建立一个新的线程来处理它
            new Thread(new Task(socket)).start();
        }
    }

    /**
     * 处理客户端传输过来的文件线程类
     */
    class Task implements Runnable {

        private final Socket socket;

        private DataInputStream dis;

        private FileOutputStream fos;

        public Task(final Socket socket) {
            this.socket = socket;
        }

        @Override
        public void run() {
            try {
                final BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
                dis = new DataInputStream(socket.getInputStream());
                // 文件名和长度
                final byte[] nameandsize=new byte[256];
                dis.read(nameandsize,0,256);
                final String nameandsize_str=new String(nameandsize,"utf-8");
                final String[] nameandsize_str_array=nameandsize_str.split("\0\0\0\0");
                final String fileName=nameandsize_str_array[0];
                final String fileLength_str=nameandsize_str_array[1];
                long fileLength=Long.parseLong(fileLength_str);
                System.out.println("fileName:  "+fileLength);
                System.out.println("fileLength:  "+fileLength);              

                final File directory = new File("E:\\FTP\\");
                if(!directory.exists()) {
                    directory.mkdir();
                }
                System.out.println("dict ok");
                final String filepath="E:\\FTP\\"+fileName;
                final File file = new File(filepath);
                System.out.println(filepath);
                System.out.println("file ok");
                fos = new FileOutputStream(file);
                
                final String str = "ok,ok";
                bufferedWriter.write(str);
                bufferedWriter.write("\n");
                bufferedWriter.flush(); // 开始接收文件
                final byte[] bytes = new byte[1024];
                int length = 0;
                int recv_size=1024;
                
                long have_recved=0;
                while (have_recved<fileLength){
                if(fileLength-have_recved<1024)
                    {
                    int recv_size_int=(int)fileLength%1024;
                    recv_size=recv_size_int;
                    }
                    length = dis.read(bytes, 0, recv_size);
                    if(length!=-1&&length>0)
                    {    
                        System.out.println("in while");
                        fos.write(bytes, 0, length);
                        fos.flush();
                        have_recved+=length;
                    }
            
                }
                bufferedWriter.write(str);
                bufferedWriter.write("\n");
                bufferedWriter.flush(); // 发送接收完毕指令
                
                System.out.println("fileLength:  " + fileLength);
                System.out.println("======== 文件接收成功 [File Name：" + fileName + "] [Size：" + fileLength
                        + "] ========");
                String md5_cal=md5.getHash(filepath,"MD5");
                System.out.println("计算得到的MD5值："+md5_cal);
                final byte[] md5_recv_byte=new byte[32];
                dis.read(md5_recv_byte,0,32);
                String md5_recv_str=new String(md5_recv_byte,"utf-8");
                System.out.println("接收到的原文件MD5值："+md5_recv_str);
                if(md5_cal.equals(md5_recv_str))
                {  bufferedWriter.write("md5_ok");
                    System.out.println("MD5值校验成功");
                    // 发送接收完毕指令}
                }
                else{ 
                    bufferedWriter.write("md5_error");
                    System.out.println("MD5值校验失败");

                }
                bufferedWriter.write("\n");
                bufferedWriter.flush();
                socket.close();
            } catch (final Exception e) {
                e.printStackTrace();
            } finally {
                try {
                    if (fos != null)
                        fos.close();
                    if (dis != null)
                        dis.close();
                    socket.close();
                } catch (final Exception e) {
                }
            }
        }
    }

    /**
     * 格式化文件大小
     * 
     * @param length
     * @return
     */


    /**
     * 入口
     * 
     * @param args
     */
    public static void main(final String[] args) {
        try {
            final Server server = new Server(); // 启动服务端
            server.load();
        } catch (final Exception e) {
            e.printStackTrace();
        }
    }


    /**  
     * @param args  
     */      
    
   
}  