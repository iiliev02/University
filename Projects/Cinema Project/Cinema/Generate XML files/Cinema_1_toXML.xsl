<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="xml" encoding="UTF-8" indent="yes"/>

    <xsl:template match="/">
        <accesses version="1.0">
            <xsl:apply-templates select="/cinema/staff"/>
        </accesses>
    </xsl:template>

    <xsl:template match="/cinema/staff">
        <xsl:for-each select = "employee">
            <employee>
                <name>
                    <xsl:value-of select="employeeName"/>
                </name>
                <job>
                    <xsl:value-of select="@job"/>
                </job>
                <conection>
                    <xsl:value-of select="employeeEmail"/>
                    <xsl:value-of select="', '"/>
                    <xsl:value-of select="employeePhone"/>
                </conection>
            </employee>
        </xsl:for-each>
    </xsl:template>

</xsl:transform>