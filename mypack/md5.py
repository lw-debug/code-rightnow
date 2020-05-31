import hashlib
import sys
def md5sum(filename):
    m = hashlib.md5()
    f = open(filename, "rb")
    for line in f:
        m.update(line)
    f.close()
    md5 = m.hexdigest()
    return md5

if __name__=="__main__":
    print("计算MD5")
    md5_res=md5sum(sys.argv[1])
    md5_res2=md5sum("E:\\FTP\\"+sys.argv[1])
    print(md5_res)
    print(md5_res2)
      
   
  