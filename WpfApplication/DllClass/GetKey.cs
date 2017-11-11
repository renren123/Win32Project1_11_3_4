using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace WpfApplication.DllClass
{
    public class GetKey
    {
        public static  bool isRun = false;
        [DllImport("Win32Project1.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MyGetKeyState(ref bool isRun, string text);//为什么在这类型为string而在dll文件中是char *，不然会出现内存错误
        [DllImport("Win32Project1.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SetIsRun(bool isRun);


        private static GetKey getKey;
        private  GetKey()
        {
        }
        public static GetKey GetObject()
        {
            if (getKey == null)
            {
                getKey = new GetKey();
            }
            return getKey;
        }
        public static void SetIsRunValue(bool isRun)
        {
            SetIsRun(isRun);
        }
        public static void StartGetKey(string filePath)
        {
            Task.Run(()=> {
                MyGetKeyState(ref isRun, filePath);
                System.Windows.MessageBox.Show("Over Success!");
            } );

            ////System.Reflection.Assembly assembly = System.Reflection.Assembly.LoadFrom("Win32Project1.dll");


            //AppDomainSetup info = new AppDomainSetup();
            //AppDomain dom = AppDomain.CreateDomain("RemoteDomain", null, info);
           
            //Assembly asm = Assembly.Load(File.ReadAllBytes("Win32Project1.dll"));
            ////Object obj = asm.CreateInstance("HelloWorld");
            //MethodInfo Method = asm.GetTypes()[0].GetMethod("MyGetKeyState");
            //Method.Invoke(null, new string[] { "true", "Task 1" });
            //AppDomain.Unload(dom);
        }
    }
}