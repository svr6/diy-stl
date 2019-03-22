(defun WriteHelloWorld(fileName)

 (with-open-file (out fileName

                     :direction :output

                     :if-exists :supersede)

(with-standard-io-syntax (print "HelloWorld" out))))
