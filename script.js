class Matrix {
    constructor(rows, columns) {
        this.rows = rows
        this.columns = columns
        this.body
        this.createBody()
    }

    // This method make a matrix of nxn
    reduceRows(n){
        this.rows = n 
        this.columns = n
        this.createBody()

        for(let i = 0; i < n; i++){
            for(let j = 0; j < n; j++){
                if(i == j){
                    this.body[i][j] = 1
                } else {
                    this.body[i][j] = 0
                }
            }
        }
    }

    createBody() {
        this.body = new Array(this.rows)
        for (let i = 0; i < this.rows; i++) {
            this.body[i] = new Array(this.columns)
        }
    }

    fillRandomNumbers() {
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < this.columns; j++) {
                this.body[i][j] = Math.round(Math.random() * 1000)
            }
        }
    }

    sortMatrix() {
        let arrayForm = new Array(this.rows * this.columns)
        let jump = 0

        // fill arrayForm of the matrix
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < this.columns; j++) {
                arrayForm[jump] = this.body[i][j]
                jump++
            }
        }

        // sort arrayForm of the matrix
        for (var i = 0; i <= arrayForm.length - 1; i++) {
            for (var j = 0; j < (arrayForm.length - i - 1); j++) {
                if (arrayForm[j] > arrayForm[j + 1]) {
                    var temp = arrayForm[j]
                    arrayForm[j] = arrayForm[j + 1]
                    arrayForm[j + 1] = temp
                }
            }
        }

        jump = 0

        // Replace the positions without order of the matrix with the new form
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < this.columns; j++) {
                this.body[i][j] = arrayForm[jump]
                jump++
            }
        }
    }
}