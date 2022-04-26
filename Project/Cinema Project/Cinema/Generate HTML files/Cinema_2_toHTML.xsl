<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html"/>

    <xsl:template match="/">
        <html lang="bg">
            <head>
                <meta charset="UTF-8"/>
                <title>Employees</title>
                <link rel="stylesheet" href="styleGenedHTMl.css"></link>
            </head>
            <body>
                <xsl:apply-templates select="/cinema/staff"/>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="/cinema/staff">
        <div class="container">
        <h2>Cinema's Employees</h2>
            <ul>
                <li class="table-header">
                    <div class="col col-1">Name</div>
                    <div class="col col-2">Job</div>
                    <div class="col col-3">Phone</div>
                    <div class="col col-4">Email</div>
                    <div class="col col-5">Salary</div>
                </li>
                <xsl:for-each select = "employee">
                    <xsl:sort select = "salary" data-type="number" order="descending"/>
                        <li class="table-row">
                            <div class="col col-1" data-label="Name"><xsl:value-of select="employeeName"/></div>
                            <div class="col col-2" data-label="Job"><xsl:value-of select="@job"/></div>
                            <div class="col col-3" data-label="Phone"><xsl:value-of select="employeePhone"/></div>
                            <div class="col col-4" data-label="Email"><xsl:value-of select="employeeEmail"/></div>
                            <div class="col col-5" data-label="Salary"><xsl:value-of select="salary"/>&#160;<xsl:value-of select="salary/@currency"/></div>
                        </li>
                </xsl:for-each>
            </ul>
        </div>
    </xsl:template>

</xsl:transform>