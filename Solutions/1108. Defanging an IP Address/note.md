## [C++ 1-liner](https://leetcode.com/problems/defanging-an-ip-address/discuss/328855/C%2B%2B-1-liner-(regex_replace))
  * ```cpp
      string defangIPaddr(string address) {
      return regex_replace(address, regex("[.]"), "[.]");
      }
    ```
    
## [Java/Python 3 One liners + one](https://leetcode.com/problems/defanging-an-ip-address/discuss/328895/JavaPython-3-3-One-liners-%2B-one-wo-lib.)
  #### Java
  * ```java
    public String defangIPaddr(String address) {
        return address.replace(".", "[.]");
    }
    public String defangIPaddr(String address) {
        return String.join("[.]", address.split("\\."));
    }
    public String defangIPaddr(String address) {
        return address.replaceAll("\\.", "[.]");
    }
    public String defangIPaddr(String address) {
        StringBuilder sb = new StringBuilder();
        for (char c : address.toCharArray()) {
            sb.append(c == '.' ? "[.]" : c);
        }
        return sb.toString();
    }
    ```
  #### Python
  * ```python
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')
    def defangIPaddr(self, address: str) -> str:
        return '[.]'.join(address.split('.'))
    def defangIPaddr(self, address: str) -> str:
        return re.sub('\.', '[.]', address)
    def defangIPaddr(self, address: str) -> str:
        return ''.join('[.]' if c == '.' else c for c in address)
    ```
    
