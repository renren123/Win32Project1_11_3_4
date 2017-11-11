using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using WpfApplication.DllClass;
using WpfApplication.LoginFile;
using WpfApplication.MyWindows.KeyWindow;
using WpfApplication.User;

namespace WpfApplication
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        UserInfo user = null;
        public MainWindow()
        {
            InitializeComponent();
            WindowStartupLocation = WindowStartupLocation.CenterScreen;
            this.SourceInitialized += MainWindow_SourceInitialized;
        }

        private void MainWindow_SourceInitialized(object sender, EventArgs e)
        {
            Login login = new Login();
            login.ShowDialog();
            
            user = login.User;
            
            
            //GetKey.isRun = true;
            //GetKey.StartGetKey("1111.txt");
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            //GetKey.isRun = false;
            //GetKey.SetIsRunValue(false);
            //System.Windows.MessageBox.Show("Button Success!");
            
        }

        private void buttonkey_Click(object sender, RoutedEventArgs e)
        {
            GetKeyWindow getKeyWindow = new GetKeyWindow();
            getKeyWindow.Show();
        }

        //private int[] ChangValueOfXY(int[] array, int count)
        //{

        //    int[] arrayXY = new int[4];
            

        //}
        private void GetJiePing()
        {
            //this.WindowState = WindowState.Minimized; //最小化当前窗口
            //System.Threading.Thread.Sleep(2000);//延时2秒

            var size = System.Windows.Forms.Screen.PrimaryScreen.Bounds.Size;
            System.Drawing.Bitmap bitmap=null;
            System.Drawing.Graphics g=null;

            int[] array = new int[4];
            StringBuilder message = new StringBuilder();
            if (GetMouseButtonUpDownPosition(ref array[0], ref array[1], ref array[2], ref array[3]) == 1)
            {
                bitmap = new System.Drawing.Bitmap(array[2] - array[0], array[3] - array[1]);
                g = System.Drawing.Graphics.FromImage(bitmap);
                g.CopyFromScreen(array[0], array[1], 0, 0, new System.Drawing.Size(array[2]- array[0], array[3]-array[1]));
                MessageBox.Show(array[0] +" "+ array[1]+" " + array[2]+" " + array[3]);
            }
            else
                MessageBox.Show("Error");
            bitmap.Save("E:\\screen.png", System.Drawing.Imaging.ImageFormat.Png);
        }
        [DllImport("Win32MouseButton.dll", CharSet = CharSet.Ansi,
        CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetMouseButtonUpDownPosition(ref int a , ref int b , ref int c , ref int d);
        private void buttonmouse_Click(object sender, RoutedEventArgs e)
        {
            Task.Run(() => 
            {
                //int[] array = new int[4];
                //StringBuilder message = new StringBuilder();
                //if (GetMouseButtonUpDownPosition(ref array[0],ref array[1], ref array[2], ref array[3]) ==1)
                //{
                //    MessageBox.Show(array[0]+array[1]+array[2]+array[3]+"");
                //}
                //else
                //    MessageBox.Show("Error");
                GetJiePing();

            });
        }
    }
}
