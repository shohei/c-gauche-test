(use rfc.http)
(use rfc.uri)

(define (uri-get uri)
 (receive (code status body)
  (receive (scheme user-info hostname port path query frament)
   (uri-parse uri)
   (if (eq? path #f)
    (http-get hostname "/")
    (http-get hostname path)))
  body))

(print (uri-get "http://example.com"))

