import java.util.*;

import javax.swing.text.html.HTMLDocument.Iterator;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class Parser {

	/*public static String stops[]={"a", "about", "above", "after", "again", "against", "all", "am", "an", "and", "any", "are", "aren't", "as", "at", "be", "because", "been", "before", "being", "below", "between", "both", "but", "by", "can't", "cannot", "could", "couldn't", "did", "didn't", "do", "does", "doesn't", "doing", "don't", "down", "during", "each", "few", "for", "from", "further", "had", "hadn't", "has", "hasn't", "have", "haven't", "having", "he", "he'd", "he'll", "he's", "her", "here", "here's", "hers", "herself", "him", "himself", "his", "how", "how's", "i", "i'd", "i'll", "i'm", "i've", "if", "in", "into", "is", "isn't", "it", "it's", "its", "itself", "let's", "me", "more", "most", "mustn't", "my", "myself", "no", "nor", "not", "of", "off", "on", "once", "only", "or", "other", "ought", "our", "ours ", "ourselves", "out", "over", "own", "same", "shan't", "she", "she'd", "she'll", "she's", "should", "shouldn't", "so", "some", "such", "than", "that", "that's", "the", "their", "theirs", "them", "themselves", "then", "there", "there's", "these", "they", "they'd", "they'll", "they're", "they've", "this", "those", "through", "to", "too", "under", "until", "up", "very", "was", "wasn't", "we", "we'd", "we'll", "we're", "we've", "were", "weren't", "what", "what's", "when", "when's", "where", "where's", "which", "while", "who", "who's", "whom", "why", "why's", "with", "won't", "would", "wouldn't", "you", "you'd", "you'll", "you're", "you've", "your", "yours", "yourself", "yourselves"};
	public static Set<String> stopWords=new HashSet<String>(Arrays.asList(stops));*/
    public static String stops[]={"a","able","about","above","abst","accordance","according","accordingly","across","act","actually","added","adj","affected","affecting","affects","after","afterwards","again","against","ah","all","almost","alone","along","already","also","although","always","am","among","amongst","an","and","announce","another","any","anybody","anyhow","anymore","anyone","anything","anyway","anyways","anywhere","apparently","approximately","are","aren","arent","arise","around","as","aside","ask","asking","at","auth","available","away","awfully","b","back","be","became","because","become","becomes","becoming","been","before","beforehand","begin","beginning","beginnings","begins","behind","being","believe","below","beside","besides","between","beyond","biol","both","brief","briefly","but","by","c","ca","came","can","cannot","can't","cause","causes","certain","certainly","co","com","come","comes","contain","containing","contains","could","couldnt","d","date","did","didn't","different","do","does","doesn't","doing","done","don't","down","downwards","due","during","e","each","ed","edu","effect","eg","eight","eighty","either","else","elsewhere","end","ending","enough","especially","et","et-al","etc","even","ever","every","everybody","everyone","everything","everywhere","ex","except","f","far","few","ff","fifth","first","five","fix","followed","following","follows","for","former","formerly","forth","found","four","from","further","furthermore","g","gave","get","gets","getting","give","given","gives","giving","go","goes","gone","got","gotten","h","had","happens","hardly","has","hasn't","have","haven't","having","he","hed","hence","her","here","hereafter","hereby","herein","heres","hereupon","hers","herself","hes","hi","hid","him","himself","his","hither","home","how","howbeit","however","hundred","i","id","ie","if","i'll","im","immediate","immediately","importance","important","in","inc","indeed","index","information","instead","into","invention","inward","is","isn't","it","itd","it'll","its","itself","i've","j","just","k","keep","        keeps","kept","kg","km","know","known","knows","l","largely","last","lately","later","latter","latterly","least","less","lest","let","lets","like","liked","likely","line","little","'ll","look","looking","looks","ltd","m","made","mainly","make","makes","many","may","maybe","me","mean","means","meantime","meanwhile","merely","mg","might","million","miss","ml","more","moreover","most","mostly","mr","mrs","much","mug","must","my","myself","n","na","name","namely","nay","nd","near","nearly","necessarily","necessary","need","needs","neither","never","nevertheless","new","next","nine","ninety","no","nobody","non","none","nonetheless","noone","nor","normally","nos","not","noted","nothing","now","nowhere","o","obtain","obtained","obviously","of","off","often","oh","ok","okay","old","omitted","on","once","one","ones","only","onto","or","ord","other","others","otherwise","ought","our","ours","ourselves","out","outside","over","overall","owing","own","p","page","pages","part","particular","particularly","past","per","perhaps","placed","please","plus","poorly","possible","possibly","potentially","pp","predominantly","present","previously","primarily","probably","promptly","proud","provides","put","q","que","quickly","quite","qv","r","ran","rather","rd","re","readily","really","recent","recently","ref","refs","regarding","regardless","regards","related","relatively","research","respectively","resulted","resulting","results","right","run","s","said","same","saw","say","saying","says","sec","section","see","seeing","seem","seemed","seeming","seems","seen","self","selves","sent","seven","several","shall","she","shed","she'll","shes","should","shouldn't","show","showed","shown","showns","shows","significant","significantly","similar","similarly","since","six","slightly","so","some","somebody","somehow","someone","somethan","something","sometime","sometimes","somewhat","somewhere","soon","sorry","specifically","specified","specify","specifying","still","stop","strongly","sub","substantially","successfully","such","sufficiently","suggest","sup","sure","t","take","taken","taking","tell","tends","th","than","thank","thanks","thanx","that","that'll","thats","that've","the","their","theirs","them","themselves","then","thence","there","thereafter","thereby","thered","therefore","therein","there'll","thereof","therere","theres","thereto","thereupon","there've","these","they","theyd","they'll","theyre","they've","think","this","those","thou","though","thoughh","thousand","throug","through","throughout","thru","thus","til","tip","to","together","too","took","toward","towards","tried","tries","truly","try","trying","ts","twice","two","u","un","under","unfortunately","unless","unlike","unlikely","until","unto","up","upon","ups","us","use","used","useful","usefully","usefulness","uses","using","usually","v","value","various","'ve","very","via","viz","vol","vols","vs","w","want","wants","was","wasn't","way","we","wed","welcome","we'll","went","were","weren't","we've","what","whatever","what'll","whats","when","whence","whenever","where","whereafter","whereas","whereby","wherein","wheres","whereupon","wherever","whether","which","while","whim","whither","who","whod","whoever","whole","who'll","whom","whomever","whos","whose","why","widely","willing","wish","with","within","without","won't","words","world","would","wouldn't","www","x","y","yes","yet","you","youd","you'll","your","youre","yours","yourself","yourselves","you've","z","zero","infobox","aa","aaa","aaaa","aaaaa"};
	public static Set<String> stopWords=new HashSet<String>(Arrays.asList(stops));
	public static Vector<String> stack1 = new Vector<String>(1000);
	public static int stack_top=0;
	public static int doc_id_flag=0;
	public static int page_ct=-1;

	public static HashMap<String, TreeSet<Integer> > map = 
			new HashMap<String, TreeSet<Integer> >();

	public static HashMap<Integer, Integer> page_id_map = 
			new HashMap<Integer, Integer>();

	public static void main(String argv[])
	{
		try {
			SAXParserFactory factory = SAXParserFactory.newInstance();
			SAXParser saxParser = factory.newSAXParser();

			DefaultHandler handler = new DefaultHandler() 
			{
				public void startElement(String uri, String localName,String tag_name, 
						Attributes attributes) throws SAXException {

					if(tag_name.equals("id"))
						doc_id_flag=1;
					if(tag_name.equals("page"))
						page_ct++;
					stack1.add(stack_top, tag_name);
					stack_top++;

					//System.out.println("Start Element " + tag_name + " " + stack_top);
				}

				public void endElement(String uri, String localName,
						String tag_name) throws SAXException {

					if(stack1.get(stack_top-1).equals(tag_name))
						stack_top--;

					//System.out.println("End Element " + tag_name + " " + stack_top);
				}

				public void characters(char ch[], int start, int length) throws SAXException {

					String word=new String(ch, start, length);
					word=word.replaceAll("\\s+"," ");

					//System.out.println("/* " + word + " */" + word.length());

					if(doc_id_flag==1 && stack_top>1 && stack1.get(stack_top-1).equals("id") 
							&& stack1.get(stack_top-2).equals("page"))
					{
						String temp1=word;
						int x=Integer.parseInt(temp1);
						page_id_map.put(page_ct,x);
						doc_id_flag=0;
						//System.out.println("Enter" + x);
						return;
					}

					String temp="";
					int l=word.length();
					for(int i=0;i<l;i++)
					{
						if((word.charAt(i)>='a' && word.charAt(i)<='z')
								|| (word.charAt(i)>='A'	&& word.charAt(i)<='Z' )
								|| (word.charAt(i)>='0' && word.charAt(i)<='9'))
						{
							temp+=word.charAt(i);
						}
						else
						{
							if(temp.equals("") || temp.matches("\\d+"))
							{
								temp="";
								continue;
							}
							temp=temp.toLowerCase();
							if(stopWords.contains(temp))
							{
								temp="";
								continue;
							}
							Stemmer stem = new Stemmer();
							stem.add(temp.toCharArray(), temp.length());
							stem.stem();
							temp=stem.toString();

							if(!(map.containsKey(temp)))
							{
								map.put(temp, new TreeSet<Integer>());
								map.get(temp).add(page_ct);
							}
							else
							{
								map.get(temp).add(page_ct);
							}
							temp="";
						}
					}
					if(temp!="" && !temp.matches("\\d+"))
					{
						temp=temp.toLowerCase();
						if(stopWords.contains(temp))
							temp="";
						else
						{
							Stemmer stemmer_object = new Stemmer();
							stemmer_object.add(temp.toCharArray(), temp.length());
							stemmer_object.stem();
							temp=stemmer_object.toString();

							if(!(map.containsKey(temp)))
							{
								map.put(temp, new TreeSet<Integer>());
								map.get(temp).add(page_ct);
							}
							else
							{
								map.get(temp).add(page_ct);
							}
						}
					}
				}
			};
			saxParser.parse(argv[0], handler);
			//System.out.println(map.size());
			printing();
		} catch (Exception e) {
			// TODO: handle exception
		}	
	}

	public static void printing()
	{
		for(Map.Entry<String, TreeSet<Integer> >it:map.entrySet())
		{
			System.out.print(it.getKey() + " ~ " );
			TreeSet <Integer> newset = new TreeSet <Integer>();
			TreeSet <Integer> temp_set = new TreeSet<Integer>();
			newset=it.getValue();
			int l=newset.size(),temp_ct=0;

			for(int it1: newset)
			{
				int temp=it1;
				if(page_id_map.containsKey(temp))
					temp_set.add(page_id_map.get(temp));
			}
			for(int it1: temp_set)
			{
				if(temp_ct!=l-1)
					System.out.print(it1 + ",");
				else
					System.out.print(it1 + "\n");
				temp_ct++;
			}
		}
	}
}