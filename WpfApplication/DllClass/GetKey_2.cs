using System;
using System.Windows;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace WpfApplication.DllClass
{
    public class GetKey_2
    {
        /// <summary>
        /// dll调用 -1：error ，1：执行成功 ，0：NULL
        /// </summary>
        /// <param name="myDll"></param>
        /// <param name="methodName"></param>
        /// <param name="theParameters"></param>
        /// <returns></returns>
        [DllImport("Win32FreeDll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int MyMethod(string myDll, string methodName, string theParameters);
        /// <summary>
        /// dll调用 -1：error ，1：执行成功 ，0：NULL
        /// </summary>
        /// <param name="methodName"></param>
        /// <returns></returns>
        [DllImport("Win32FreeDll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int FreeDll(string methodName);
        private static GetKey_2 getKey_2;
        private GetKey_2()
        {

        }
        public static GetKey_2 GetObject()
        {
            if (getKey_2==null)
            {
                getKey_2 = new GetKey_2();
            }
            return getKey_2;
        }
        public static void StartGetKey(string fileName)
        {
            Task.Run(() => {
                try
                {
                    if(MyMethod("Win32Project1.dll", "MyGetKeyState", "true/" + fileName + "/2")!=1)
                    {
                        MessageBox.Show("MyMethod函数出错");
                    }
                }
                catch (Exception ew)
                {
                    MessageBox.Show(ew.Message, "Error", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Error);
                }
                   
            });
        }
        public static void SetIsRunValue()
        {
            switch (FreeDll("SetIsRun"))
            {
                case 1:
                    MessageBox.Show("释放DLL成功！", "Success", MessageBoxButton.OK, MessageBoxImage.Information);
                    break;
                case -1:
                    MessageBox.Show("释放DLL出错!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                    break;
                case 0:
                    MessageBox.Show("DLL为空，请检查文件名！", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                    break;
                default:
                    MessageBox.Show("FreeDLL出错!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                    break;
            }
        }

    }
}
