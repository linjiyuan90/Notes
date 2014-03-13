# regex
``` java
public static Version parseLeniently(String version) {
  String parsedMatchVersion = version.toUpperCase(Locale.ROOT);
  return Version.valueOf(parsedMatchVersion.replaceFirst("^(\\d)\\.(\\d)$", "LUCENE_$1$2"));
}
```
