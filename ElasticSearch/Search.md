# Note
## match & term
* `match` will analyzes the terms while `term` won't
```{"query": {"match": {"title": "toKyo"}}}```

## multi match
* the `multi_match` query builds on the `match query` to allow multi-field queries

## query string query
* will use a **query parser** in order to parse its content
* fuzziness, use Damerau-Levenshtein distance; default edit distance is 2. `quikc~1 brwn~`
* proximity searches; while a `phrase query` expects all of the terms in exactly the same order, a proximity  query allows the specified words to be futher apart or in a different order.

## simple query string query
* A query that uses the SimpleQueryParser to parse its context. Unlike the regular query_string query, the simple_query_string query will never throw an exception, and discards invalid parts of the query.

## dis max query
* a query that generats the union of the documents produced by its subqueries

## request body in query string
* For libraries that don’t accept a request body for non-POST requests, you can pass the request body as the `source` query string parameter instead.
```http://ada-datanode1:9200/el/doc/_search?source={"query": {"match_phrase": {"raw_doc_content": "Mr. H."}}}```


