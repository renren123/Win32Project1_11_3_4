using System;
using System.Collections.Generic;
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

namespace WpfApplication.MyWindows.KeyWindow
{
    /// <summary>
    /// GetKeyWindow.xaml 的交互逻辑
    /// </summary>
    public partial class GetKeyWindow : Window
    {
        public GetKeyWindow()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            GetKey_2.SetIsRunValue();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            GetKey_2.StartGetKey("123.txt");
        }
    }
}
