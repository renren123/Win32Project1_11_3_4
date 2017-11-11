using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfApplication.DllClass
{
    public static class IniClass
    {
        public static bool IniAllClass()
        {
            try
            {
                GetKey getKey = GetKey.GetObject();
                GetKey_2 getKey_2 = GetKey_2.GetObject();
            }
            catch
            {
                return false;
            }
            
            return true;
        }
    }
}
