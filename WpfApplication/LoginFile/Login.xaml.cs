using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using WpfApplication.DllClass;
using WpfApplication.User;

namespace WpfApplication.LoginFile
{
    /// <summary>
    /// Login.xaml 的交互逻辑
    /// </summary>
    public partial class Login : Window
    {
        /// <summary>
        /// 配置文件，用于记录用户名
        /// </summary>
        private string configuration = "configurationFile.txt";
        private string userPath = @"./User/";
        private UserInfo user;

        internal UserInfo User
        {
            get
            {
                return user;
            }

            set
            {
                user = value;
            }
        }

        public Login()
        {
            InitializeComponent();
            this.WindowStartupLocation = WindowStartupLocation.CenterScreen;
            
            Task.Run(() => Initial());
        }
        private  void Initial()
        {
            ChangeLabelMessage("正在初始化");
            if (!InitialUser(userPath + configuration))
            {
                ChangeLabelMessage("初始化失败！");
            }
            ChangeLabelMessage("正在读取用户信息");
            if (!InitialUserInfo(userPath))
            {
                ChangeLabelMessage("读取用户信息失败！");
            }
            ChangeLabelMessage("正在初始化DLL文件。。");
            if (!IniClass.IniAllClass())
            {
                ChangeLabelMessage("初始化DLL文件失败！");
            }
            this.Dispatcher.Invoke(() => this.Close());
        }
        /// <summary>
        /// 读取用户信息，读取用户文件
        /// </summary>
        /// <param name="userInfo">用户目录</param>
        /// <returns></returns>
        private bool InitialUserInfo(string userInfo)
        {
            string userInfoNameFile = userInfo+ User.UserName+"/" + User.UserName + ".txt";
            string userInfoDirectory = userInfo + User.UserName;
            if (!File.Exists(userInfoDirectory))
            {
                Directory.CreateDirectory(userInfoDirectory);
            }
            if (!File.Exists(userInfoNameFile))
            {
                File.Create(userInfoNameFile);
            }
            
            return true;
        }
        /// <summary>
        /// 读取登陆用户信息，实例化用户
        /// </summary>
        /// <param name="userConfigurationPath">保存用户的文件</param>
        /// <returns></returns>
        private bool InitialUser(string userConfigurationPath)
        {
            User = new UserInfo();
            string strInfo = "";
            if (!File.Exists(userConfigurationPath))
            {
                return false;
            }
            try
            {
                using (StreamReader sr = new StreamReader(userConfigurationPath,Encoding.UTF8))
                {
                    string line = "";
                    while ((line = sr.ReadLine()) != null)
                    {
                        strInfo += line.Trim();
                    }
                }
            }
            catch (Exception ew)
            {
                MessageBox.Show(ew.Message);
                return false;
            }
            string[] strInfoSplit = strInfo.Split('/');
            User.UserName = strInfoSplit[0];
            User.Sex = strInfoSplit[1];
            int a = 0;
            int.TryParse(strInfoSplit[2], out a);
            User.Age = a;
            return true;
        }
        private void ChangeLabelMessage(string message)
        {
            labelInfo.Dispatcher.Invoke(() => {
                labelInfo.Content = message;
            });
        }
    }
}
