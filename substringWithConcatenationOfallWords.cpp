// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

// O(n^2) solution using trie

class Solution {
    
    struct Node {
        Node() : leaf(false) {
            nodes.resize(255);
        }
        vector<Node*> nodes;
        bool leaf;
    } root;
    
    // map word to count
    unordered_map<Node *, int> leafs;
    
public:

    void buildTree(vector<string> &words) {
        for (auto w : words) {
            Node *curr = &root;
            
            for (auto c : w) {
                if (curr->nodes[c] == nullptr)
                    curr->nodes[c] = new Node();
                curr = curr->nodes[c];
            }
            curr->leaf = true;
            leafs[curr]++;
        }
    }

    bool match(string s, int begin) {
        Node *curr = &root;
        
        auto l = leafs;
        for (int i = begin; i < s.size(); i++) {
            auto c = s[i];
            
            curr = curr->nodes[c];
            if (!curr)
                return false;
            if (curr->leaf == false)
                continue;
            // one word too many
            if (l.find(curr) == l.end())
                return false;
            // decrement count, remove if all occurences found
            if (--l[curr] == 0)
                l.erase(curr);
            // all words found
            if (l.empty())
                return true;
            // back to root
            curr = &root;
        }
        return false;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        Node *curr = &root;
        
        buildTree(words);
        for (int i = 0; i < s.size(); i++) {
            if (match(s, i))
                res.push_back(i);
        }
        return res;
    }
};

// O(n) solution

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> wordMap;
        
        if (words.empty())
            return {};
        
        auto wordSize = words.back().size();
        auto totalWordSize = words.size() * wordSize;
        
        for (auto &w : words)
            wordMap[w]++;
        
        // Take advantage of fact that all words have equal size
        for (int begin = 0; begin + totalWordSize <= s.size(); begin++) {
            auto currWordMap = wordMap;
            
            for (int i = 0; i < words.size(); i++) {
                size_t pos = begin + i * wordSize;
                auto w = s.substr(pos, wordSize);
                auto wIter = currWordMap.find(w);
                
                // not matching any word
                if (wIter == currWordMap.end())
                    break;
                if(--wIter->second == 0)
                    currWordMap.erase(wIter);
                if (currWordMap.empty()) {
                    res.push_back(begin);
                    continue;
                }
            }
        }
        return res;
    }
};

// Sample input
// "aratdgpfsookqyxiptwjllwirwmfdmafdayignqadektejbvcaepnbyezmlcalkfnkovaeydkixqsalwaqmptmwsajwaxifktvitbgwlqvdiwphyhtochmwhvujsdofymptnvpzlnewjtfhcaxghjeqhzzzepgebvxpqoqebuckqhuuhtbqdfgmghlmwuqypppiefofbqsrzooihpymwgyfnmrlgkjxzaffftnjlfamvoucfurecpjpdcblomjqnovukidvpgikwepebgidxttdxwomkzczqxuaizxxhfkembinjsqglllijcwubytryptgrrfyypekqmxzeqirbvclxyhbxcuxuodlfilfaqqsepulfecjzgwzfdaehubbkeorocxqunjycflkjqtkwpjbsjfbggdqmtibvhtpucqyjbisrbfosopmaxogdryqmitkpmzlrrkatuvmyaaqosdqpryukxkwhfgzuiklzwnurkhpkjfbbirsbqnlpzkyfsxbcimeebyxmhmyruzsctlglytaxfyeyyfcgtgmxfkjowjfqjyveldplwricppcnwevsnkpuuaisjoluoiyzlnkjeulwlpliujahtrdntlhczsxncxonlyxrvkngabowkqffjiuctbhvweiybxmoxlisvvzxyptkiyprijwcndxjjhhmgvbeijwegvdhnxrvxjoiskmfnloysylzvmfexbifznmmmgjkpxujkgpzrfyjfjkbxpfwtpbscqgpwrbnovwadlautyfahqbehiccxdwctcrrvuekrbkuokojktkrlnxvwzxtfuvayosuiygzzstqfjzpfljszinvilqphopfejzpihqjamzfvbuamftloiiyvbncrekvolkytbhtnjakkulwagkqquomvbomhykvkuvdxdykoyvyuiwwqgmgdasydjnlhxitreyrjwbxwyxritnacahfcbdgksrupzpjfoaomdnjekamepngpwlsxqakjrgasvjyjlowpcftohhuwwaounisgiepbkpthbtrmipbmuwcdgxzczpxnxrthxkijbeqcxhphysvuryxzxzbwoalmtgvsqedsiuwhdlrcgmwzmuyjvbijetxzatsszvmjrjqvwhzeuvdirbumdcyhxvizqaspygyprrmoyluuhyfabzpgbnpykyadasuyavosmaimocjxcoxgnooqdeqqeqtekpflktfyvnllruiwigexwsnaydqcwljgaotljyjgnwshsafaijzfdmfcsvgogruifovqohxcdrjwroyazyfcmmgejpsrgnzodvercdtfuedoueotcvyqhgvsvnjeciuhfazheupabuovycrczptixoatdlziutpbtqjzlaamuojvtaxsrsdpidkmplulejmzcxznzbbupkrinqdgjgvrlhdcsznylcynbzcbadxppoaeedlplihwqmzkoojbqjouksvkvubmidtoiegtonqgbrrrfcsynisxanjxhkmrqfhylnszckigbbxgdqeqawpblyyukmlarvzcitelfmtgnqosivkjtzmfxmzjznkqilvsgzflnytcpjwzegkyfwfejgnivzadkvyswdflcyptilsmrdmybrckasuvrxzeszyrceeecuxmfsbxxnvyhalhuhcnedrzcsqfwulyqlnwdovcbsaksnrmvwczztyelqljnwkdhxzmlwooprzheqwzoyzotzuhsfqfbailzkzkgobxfaflsdlhdmxylrhdwykzavkchkmpannhpuskxdrcrocfhkkdkvemqrozddodsbmivesuklybbbgintnxorjgiafldvqxxcfujzptmnwnqfxdymcoemwoobcrwuovxwqgxfbmuzznezselvsrhoivrmoqgeldcdlakomfonuuomzahttqkdndpdvwihzkknmxbaeroymcmneuiamudaytftpncqapdmmhnqadomhcbmwkmlgrneksazicqitvwfelxfontyqvkohyznrmuchubpytxsrvzvhxaxmuvcrhryhsnzfhbmdedcacwrxxmeupejjzlcjeaqxprexssazvezxaquyebuthdegrgrviisybwxuozvleuiemfeqizmpeqxvzprjzljakguagrmmlwszdxqlyeacuyavnrfmeomqxjrfcfrqbjpfihsgltlitldiekwibkzavsfyxyoajdhsnaayvliqyoycyunbgobcggcfgqhqvpkirkjmytcwhcbiyojeelimtkracysypcigotuopynwaoeyeqfibnuwynwcnqcdsnljggxxemuhaafgskovaksyzqcnhfsbsdkalkyswuzzugfnrwiricritvvaandssoveatwynxxjdfywbjpllitgeoiedmzwcwccpyaexapafqzizotmxntddbjhnifrghtxhwdewtgblfjkwcyvrravvjeiujaasvyzrbfnwlqhtbrrgqoxjouexyprjrsdmscgtjvqxoxsprjvjzvunpzkqqebhyfvqjdjtzbspbkeuvcduxxhoytgoxkvvptnawxvxanmbzrvuvaouavkyprpobkmsfzucyqzzfoafhyzcaoyalizczorcafuiepkdhlcmberietmfhkhutgxuwqxzvthbktergieipxqvqfazpiuiqrdphcqevzfgsmzaudildbhtgjvvtpgmglbpptvksasmosmlxvwawfweprbkghwouzfjsawmcqyrilcggaieggkxzlhhvgvrfcbaczmhpnayyeggeqmkzwjyjrgezdwegzgkytrpgtpgxxmcoaopwynhrtmqzkwfjdrjylageqocncgdcusaughnbtfcfchqhbbhmcpssduhfaljxdjtlqhpmmrrqbkzcliqnxihcfpjhcsehdatwhkivbboennizwyovjwyonhvpccyfctbldlghpulckwdgusbfobtdlruntsuvmyiplowalkfvgibcaeiqgdvrupgnickwasnmjkouwvpegsgiwqbeuwxoofeyiquijhwutnorkfvqxezvuaaoyzfmfjknzgxkowgjlubvzwoycnuxpwnnvsccdorfvprlnyuyuvvuujswyovpkjdidhkjveoqvfbifyiatfuproopflfpukzarmjmqxfleivkgdkckgrbwhtbtytpkspdeyruxwhefcqlhcnsihvgookjodzyxodcpvyorisykimukboukjdbankosjppastpnufhcyhoivivxwphisiihvwzenregkvvebcgbmxlhfggewomqywatsbagsgodcjjfosiaptjwcqaagoseksafuanoibrmmdtavbcmxmizcjzizrokmqrgseubhontrhwokyahmiiqthyvbpfnfwvycrzjhmeyvaogboppzyguhgpkvwxbuuzwmahtomukoksrbhhafnwptozpkzshttdhtndhzztpjlhkvomadlrwzrnlsfsnayxtladmbybkmixhyjjbwbavunjmvbzvbwrmywyzwcmikjplszmrammwcvizzjwagpngnngkpsscbinvjbmjqbfsyptxyraghpnueveupxyshlpqoebehiyfxtfxlfeswtoaqtwhsuzzhqrwuscbabjxuqwfxaztvotnjqubmtcuktsgnuknxvmulkbilbbirwwaoqdbmhxycrgpnqellshycigpjjycgwcumhxaowysnfhbxnolhvjkdqbpzbthxycmfbmwynonsyqpleatbmfhcgydkrlhpnvxqktoxjerhugvzjqcvxjzfhcpbnzqcupteijdunudkdyjmqnjnxkvgmkhcjaegpzmalquakxknyvbojmeiwzollynvytdpvrpghlgulthjolzxxdfwewhquwnupslmjbsroblzuuikhkkfnrbunkmjgzfxrrkcuctifgibdqmkcwrsnumdeyokzukqlushyopgwxhzqtmsrdkhyykewyrvubnhxiovwebudjwveioynafnzrsxrltmmitjqkgooiltthpzrdzefeuexocpzxbnhwyageowozqjihjzmigrpaymqcdpzgcidailgxkvyaejjpivaqmpskdimhznnbwsdegmdqheqnnzfxwfqiwivbthksxawvsbbynhowlgmahrzdypouajvtsilpihkajobwvrviyhihyjnwbbsbmpuexhufpgiaujyratzachkctzauasvmkrsjaoprxzrrislklknqszsnythaneoxxghxvypsxilhawtohiebhyqhrxhhdvgaepzbnqvmzgtbfppoxvrfuhongwujtblxqmygdtsecofjdxxasqhoxwcfuyqnbbnuplashuyjiesnbrqvhzkgxmlrmbhoeuithiooeoznstcvmsttsdbrrojdrsrvmbrtlhkqvlfqfhnrcgnulqlcfwiwobucdnyowketvjlctzuvhjrtzexedfdrhzwkmuakghdbsrelsaibjzukeuphzuaityuhuvtaeyewpiihkqjtsfdybufbqhlliiucdndjmhfdrpnbgwwadzyfwfimovawduziierwlxzemmfukbuocsvyzfnoankejjmrnepadpepdjkomgepbzpageogtzkdizwydmyiddxgojubqystzhtfmiofhykrzhpevomytkehvbknbcgdmakyiyfrzsiybadwqpwjzcsxdfkhhrkvtuvbtdssvcqwcvuslqdmsyjydufmnrigldjggdadftzkotezlimeixeltjxgahonlxwtcwxkpyuguaffktlsrpdmydtakjqxjmtliqxaqrgkunqejbxctcorhjustkrewkpgcngtgodcevhpzgrskhlsrfmmrdqpqhwswelfvrhzoqonyhhjotbhaptusljivfbrmoyhhigwywlxdtirojzoyuisiuddbgwnuxwefccdapcdkkxyvyptszoctrfvxektbhzilblororbyqcworpjqflmwtjvztpacqkqsvellvommqiajzlafxodqxbpqsrviblaypnkmeyyugbehmgolwsbtvslnjgvkrylinvvrvvmbwsilazwwraroscbejyqcwblkygdtbrualfnleljxlclgfokqmaslefxclawpssrdzerdrccffplkdxaszuddaainaeeswvywbpbvtgayvnkbkmtlhwrjyzyyddtbatzcidxbjzcgmmjyzejicarabpbeuuivphxxkwavvcejrnhqusawvrxwiyddulyjuxifvkcspgbgwkyqeamzrlyblbghogsifapansscavkwfkokkdldojgcmnjavclbeabrswvvrhtzrildlwgbindwcpzxrkyvkcpfykarutslbdpocxskkxgomfmfrmbcoshmehgyaymecbueamqlmybygnexahzobidfplgsjsynvstvhlitkktszzpzirqjbvptgxlrplhkfahmoqhaadszcjblctweonxwkkpzxwlcztrnjynldhmiqnvvgrzwfyurkkthgejhzawkbjxeskolxjggbheihzzrjsarzjbymxlpjivbskostuaudeckfedowdivplwbihqtpnxixlcricllgqymubcsfmowxkzirrbieaqcmstuwgffwdrshvlokbkjnjtgaxogxhijbbfyildgqwbzrondpznckiimfytdfbmhfsfpfkvxgyxzmmddosfyaplgqelvhzemtjbatzybxxbmlgpzyxyaoliertcytgnosoplppppmqbzwszwpzygmhkdcmdxtqmlhbywqpnefqddjebadagpjtulhyjaovnxyowodjulaxolcsnhsuzbptowtxziuohscdiinctpcjagbnnvjoyaknxdkynfmvzryiznmscodewfumafazgmodsydhfpcfgdpfsdzxudbqkvcmbdnjrbmjarrhgvonafut"
// ["vkyprpobkmsfzucyqzzfoafhyzca","gdvrupgnickwasnmjkouwvpegsgi","jzukeuphzuaityuhuvtaeyewpiih","syzqcnhfsbsdkalkyswuzzugfnrw","kygdtbrualfnleljxlclgfokqmas","pqoqebuckqhuuhtbqdfgmghlmwuq","ycrgpnqellshycigpjjycgwcumhx","vgogruifovqohxcdrjwroyazyfcm","lefxclawpssrdzerdrccffplkdxa","vyqhgvsvnjeciuhfazheupabuovy","fexbifznmmmgjkpxujkgpzrfyjfj","qthyvbpfnfwvycrzjhmeyvaogbop","rvvmbwsilazwwraroscbejyqcwbl","jzlafxodqxbpqsrviblaypnkmeyy","vrhzoqonyhhjotbhaptusljivfbr","trfvxektbhzilblororbyqcworpj","sybwxuozvleuiemfeqizmpeqxvzp","bxgdqeqawpblyyukmlarvzcitelf","tjxgahonlxwtcwxkpyuguaffktls","ebhyfvqjdjtzbspbkeuvcduxxhoy","rplhkfahmoqhaadszcjblctweonx","obxfaflsdlhdmxylrhdwykzavkch","hykrzhpevomytkehvbknbcgdmaky","tuvbtdssvcqwcvuslqdmsyjydufm","bkmtlhwrjyzyyddtbatzcidxbjzc","nrigldjggdadftzkotezlimeixel","tjqkgooiltthpzrdzefeuexocpzx","astpnufhcyhoivivxwphisiihvwz","plashuyjiesnbrqvhzkgxmlrmbho","ieaqcmstuwgffwdrshvlokbkjnjt","dewtgblfjkwcyvrravvjeiujaasv","hzeuvdirbumdcyhxvizqaspygypr","bbupkrinqdgjgvrlhdcsznylcynb","mwzmuyjvbijetxzatsszvmjrjqvw","lsxqakjrgasvjyjlowpcftohhuww","datwhkivbboennizwyovjwyonhvp","stuaudeckfedowdivplwbihqtpnx","chkctzauasvmkrsjaoprxzrrislk","sypcigotuopynwaoeyeqfibnuwyn","izwydmyiddxgojubqystzhtfmiof","rsrvmbrtlhkqvlfqfhnrcgnulqlc","tmfhkhutgxuwqxzvthbktergieip","kmpannhpuskxdrcrocfhkkdkvemq","pvyorisykimukboukjdbankosjpp","fahqbehiccxdwctcrrvuekrbkuok","nuuomzahttqkdndpdvwihzkknmxb","agpngnngkpsscbinvjbmjqbfsypt","zcbadxppoaeedlplihwqmzkoojbq","bgwnuxwefccdapcdkkxyvyptszoc","xzeszyrceeecuxmfsbxxnvyhalhu","evhpzgrskhlsrfmmrdqpqhwswelf","euithiooeoznstcvmsttsdbrrojd","ibdqmkcwrsnumdeyokzukqlushyo","babjxuqwfxaztvotnjqubmtcukts","kqjtsfdybufbqhlliiucdndjmhfd","csynisxanjxhkmrqfhylnszckigb","dtsecofjdxxasqhoxwcfuyqnbbnu","owkqffjiuctbhvweiybxmoxlisvv","kbxpfwtpbscqgpwrbnovwadlauty","nepadpepdjkomgepbzpageogtzkd","mmhnqadomhcbmwkmlgrneksazicq","rjgiafldvqxxcfujzptmnwnqfxdy","tgoxkvvptnawxvxanmbzrvuvaoua","oyalizczorcafuiepkdhlcmberie","wcnqcdsnljggxxemuhaafgskovak","tfcfchqhbbhmcpssduhfaljxdjtl","gdryqmitkpmzlrrkatuvmyaaqosd","zmhpnayyeggeqmkzwjyjrgezdweg","qflmwtjvztpacqkqsvellvommqia","rbhhafnwptozpkzshttdhtndhzzt","kqmxzeqirbvclxyhbxcuxuodlfil","epnbyezmlcalkfnkovaeydkixqsa","crczptixoatdlziutpbtqjzlaamu","avclbeabrswvvrhtzrildlwgbind","jbxctcorhjustkrewkpgcngtgodc","xwhefcqlhcnsihvgookjodzyxodc","vgmkhcjaegpzmalquakxknyvbojm","pjlhkvomadlrwzrnlsfsnayxtlad","rzheqwzoyzotzuhsfqfbailzkzkg","pbnzqcupteijdunudkdyjmqnjnxk","zxxdfwewhquwnupslmjbsroblzuu","zselvsrhoivrmoqgeldcdlakomfo","qjamzfvbuamftloiiyvbncrekvol","xyowodjulaxolcsnhsuzbptowtxz","puuaisjoluoiyzlnkjeulwlpliuj","dpzgcidailgxkvyaejjpivaqmpsk","mfbmwynonsyqpleatbmfhcgydkrl","qhpmmrrqbkzcliqnxihcfpjhcseh","pflktfyvnllruiwigexwsnaydqcw","mdedcacwrxxmeupejjzlcjeaqxpr","bnhwyageowozqjihjzmigrpaymqc","njsqglllijcwubytryptgrrfyype","moyhhigwywlxdtirojzoyuisiudd","gaxogxhijbbfyildgqwbzrondpzn","qpryukxkwhfgzuiklzwnurkhpkjf","rjzljakguagrmmlwszdxqlyeacuy","eivkgdkckgrbwhtbtytpkspdeyru","ikhkkfnrbunkmjgzfxrrkcuctifg","sdmscgtjvqxoxsprjvjzvunpzkqq","mywyzwcmikjplszmrammwcvizzjw","ixlcricllgqymubcsfmowxkzirrb","ahtrdntlhczsxncxonlyxrvkngab","lruntsuvmyiplowalkfvgibcaeiq","wqpnefqddjebadagpjtulhyjaovn","eiwzollynvytdpvrpghlgulthjol","tqfjzpfljszinvilqphopfejzpih","gnuknxvmulkbilbbirwwaoqdbmhx","ypouajvtsilpihkajobwvrviyhih","smlxvwawfweprbkghwouzfjsawmc","uvvuujswyovpkjdidhkjveoqvfbi","vyswdflcyptilsmrdmybrckasuvr","avnrfmeomqxjrfcfrqbjpfihsglt","rpdmydtakjqxjmtliqxaqrgkunqe","pmqbzwszwpzygmhkdcmdxtqmlhby","vvcejrnhqusawvrxwiyddulyjuxi","aounisgiepbkpthbtrmipbmuwcdg","nlhxitreyrjwbxwyxritnacahfcb","wivbthksxawvsbbynhowlgmahrzd","zxyptkiyprijwcndxjjhhmgvbeij","zgkytrpgtpgxxmcoaopwynhrtmqz","zgtbfppoxvrfuhongwujtblxqmyg","kvkuvdxdykoyvyuiwwqgmgdasydj","jouksvkvubmidtoiegtonqgbrrrf","yjnwbbsbmpuexhufpgiaujyratza","zflnytcpjwzegkyfwfejgnivzadk","eksafuanoibrmmdtavbcmxmizcjz","qyrilcggaieggkxzlhhvgvrfcbac","ayvliqyoycyunbgobcggcfgqhqvp","wqbeuwxoofeyiquijhwutnorkfvq","lgkjxzaffftnjlfamvoucfurecpj","yxzxzbwoalmtgvsqedsiuwhdlrcg","pdcblomjqnovukidvpgikwepebgi","lwaqmptmwsajwaxifktvitbgwlqv","zlnewjtfhcaxghjeqhzzzepgebvx","jowjfqjyveldplwricppcnwevsnk","hcnedrzcsqfwulyqlnwdovcbsaks","kwfjdrjylageqocncgdcusaughnb","mlgpzyxyaoliertcytgnosoplppp","nvstvhlitkktszzpzirqjbvptgxl","ccyfctbldlghpulckwdgusbfobtd","faqqsepulfecjzgwzfdaehubbkeo","dgksrupzpjfoaomdnjekamepngpw","dosfyaplgqelvhzemtjbatzybxxb","bbirsbqnlpzkyfsxbcimeebyxmhm","kirkjmytcwhcbiyojeelimtkracy","yruzsctlglytaxfyeyyfcgtgmxfk","fxtfxlfeswtoaqtwhsuzzhqrwusc","xzczpxnxrthxkijbeqcxhphysvur","itvwfelxfontyqvkohyznrmuchub","fwiwobucdnyowketvjlctzuvhjrt","awtohiebhyqhrxhhdvgaepzbnqvm","mbybkmixhyjjbwbavunjmvbzvbwr","ywbjpllitgeoiedmzwcwccpyaexa","pgwxhzqtmsrdkhyykewyrvubnhxi","iricritvvaandssoveatwynxxjdf","zexedfdrhzwkmuakghdbsrelsaib","ypppiefofbqsrzooihpymwgyfnmr","lknqszsnythaneoxxghxvypsxilh","rocxqunjycflkjqtkwpjbsjfbggd","qmtibvhtpucqyjbisrbfosopmaxo","nrmvwczztyelqljnwkdhxzmlwoop","vosmaimocjxcoxgnooqdeqqeqtek","exssazvezxaquyebuthdegrgrvii","yzrbfnwlqhtbrrgqoxjouexyprjr","hpnvxqktoxjerhugvzjqcvxjzfhc","ifapansscavkwfkokkdldojgcmnj","gmmjyzejicarabpbeuuivphxxkwa","mtgnqosivkjtzmfxmzjznkqilvsg","aeroymcmneuiamudaytftpncqapd","ovwebudjwveioynafnzrsxrltmmi","litldiekwibkzavsfyxyoajdhsna","wkkpzxwlcztrnjynldhmiqnvvgrz","szuddaainaeeswvywbpbvtgayvnk","kkxgomfmfrmbcoshmehgyaymecbu","dimhznnbwsdegmdqheqnnzfxwfqi","xqvqfazpiuiqrdphcqevzfgsmzau","eamqlmybygnexahzobidfplgsjsy","pytxsrvzvhxaxmuvcrhryhsnzfhb","wegvdhnxrvxjoiskmfnloysylzvm","xezvuaaoyzfmfjknzgxkowgjlubv","pafqzizotmxntddbjhnifrghtxhw","lxzemmfukbuocsvyzfnoankejjmr","rpnbgwwadzyfwfimovawduziierw","rozddodsbmivesuklybbbgintnxo","izrokmqrgseubhontrhwokyahmii","ojvtaxsrsdpidkmplulejmzcxznz","diwphyhtochmwhvujsdofymptnvp","dildbhtgjvvtpgmglbpptvksasmo","rmoyluuhyfabzpgbnpykyadasuya","ojktkrlnxvwzxtfuvayosuiygzzs","ugbehmgolwsbtvslnjgvkrylinvv","mcoemwoobcrwuovxwqgxfbmuzzne","aowysnfhbxnolhvjkdqbpzbthxyc","mgejpsrgnzodvercdtfuedoueotc","fyiatfuproopflfpukzarmjmqxfl","zwoycnuxpwnnvsccdorfvprlnyuy","ckiimfytdfbmhfsfpfkvxgyxzmmd","kytbhtnjakkulwagkqquomvbomhy","dxttdxwomkzczqxuaizxxhfkembi","fvkcspgbgwkyqeamzrlyblbghogs","wcpzxrkyvkcpfykarutslbdpocxs","enregkvvebcgbmxlhfggewomqywa","iyfrzsiybadwqpwjzcsxdfkhhrkv","wfyurkkthgejhzawkbjxeskolxjg","xyraghpnueveupxyshlpqoebehiy","gbheihzzrjsarzjbymxlpjivbsko","pzyguhgpkvwxbuuzwmahtomukoks","tsbagsgodcjjfosiaptjwcqaagos","ljgaotljyjgnwshsafaijzfdmfcs"]

