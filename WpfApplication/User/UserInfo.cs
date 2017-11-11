using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfApplication.User
{
    class UserInfo
    {
        /// <summary>
        /// 默认为null
        /// </summary>
        private string userName = "";

        public string UserName
        {
            get
            {
                if (userName=="")
                {
                    return "null";
                }
                return userName;
            }

            set
            {
                if (value==null||value.Trim()=="")
                {
                    userName ="null";
                }
                else
                    userName = value;
            }
        }
        /// <summary>
        /// 默认为male
        /// </summary>
        private string sex = "";
        public string Sex
        {
            get
            {
                if (sex=="")
                {
                    return "male";
                }
                return sex;
            }

            set
            {
                if (value==null||value.Trim()=="")
                {
                    sex = "male";
                }
                else
                    sex = value;
            }
        }
        /// <summary>
        /// 默认为 0
        /// </summary>
        private int age = 0;
        public int Age
        {
            get
            {
                return age;
            }

            set
            {
                if (value<0 || value>200)
                {
                    age = 0;
                }
                else
                    age = value;
            }
        }

        


        

    }
}
