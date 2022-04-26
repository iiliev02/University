<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html"/>

    <xsl:template match="/">
        <html lang="bg">
            <head>
                <meta charset="UTF-8"/>
                <title>Food</title>
                <link rel="stylesheet" href="styleGenedHTMl.css"></link>
                <style>
                    .col-1 {
                    flex-basis: 25%;
                    }
                    .col-2 {
                    flex-basis: 25%;
                    }
                    .col-3 {
                    flex-basis: 25%;
                    }
                    .col-4 {
                    flex-basis: 25%;
                    }
                    .col {
                    flex-basis: 100%;
                    }
                </style>
            </head>
            <body>
                <xsl:apply-templates select="/cinema/food"/>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="/cinema/food">
        <div class="container">
            <h2>Food</h2>
            <ul>
                <li class="table-header">
                    <div class="col col-1">Name</div>
                    <div class="col col-2">Type</div>
                    <div class="col col-3">Quantity</div>
                    <div class="col col-4">Price</div>
                </li>
                <xsl:for-each select = "offer[@type='Храна']">
                    <xsl:sort select = "price" data-type="number" order="ascending"/>
                    <li class="table-row">
                        <div class="col col-1" data-label="Name"><xsl:value-of select="productName"/></div>
                        <div class="col col-2" data-label="Type"><xsl:value-of select="@type"/></div>
                        <div class="col col-3" data-label="Quantity"><xsl:value-of select="quantity"/></div>
                        <div class="col col-4" data-label="Price"><xsl:value-of select="price"/>&#160;<xsl:value-of select="price/@currency"/></div>
                    </li>
                </xsl:for-each>
            </ul>
        </div>
    </xsl:template>

</xsl:transform>