using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Siszarp_ucze_sie
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Deklaruje i inicjuję klasę czytelnik\n");
            czytelnik x = new czytelnik();
            x.Przedstaw();
            Console.WriteLine("Deklaruje i inicjuję klasę osoba\n");
            osoba y = new osoba();
            y.Przedstaw();
            Console.WriteLine("Nacisnij dowolny przycisk by wyjsc\n");
            Console.ReadKey();
        }
    }
    public class osoba
    {
        public string imie, nazwisko;
        public UInt16 wiek;
        public osoba()
        {
            Console.WriteLine("Podaj imie, nazwisko i wiek\n");
            this.imie = Console.ReadLine();
            this.nazwisko = Console.ReadLine();
            this.wiek = Convert.ToUInt16(Console.ReadLine());
        }
        public void Przedstaw()
        {
            Console.WriteLine("Osoba ma na imie: " + imie + "\nNa nazwisko: " + nazwisko + "\nMa " + wiek + " lat");
        }
    }
    class czytelnik : osoba
    {
        private UInt32 nrKsiazki;
        new public void Przedstaw()
        {
            Console.WriteLine(this.imie + " " + this.nazwisko + "\nWypozyczyl ksiazke z nr " + nrKsiazki);
        }
        public czytelnik() : base()
        {
            Console.WriteLine("Dopisz numer ksiazki do osoby");
            this.nrKsiazki = Convert.ToUInt32(Console.ReadLine());
        }
    }
}
