<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="UTF-8" indent="yes"/>

    <xsl:variable name="separator" select="' | '"/>
    <xsl:variable name="new_row" select="'&#13;'"/>

    <xsl:template name="contacts" match="/">
        <xsl:text>Cinema: </xsl:text><xsl:value-of select="cinema/cinemaName"/>
        <xsl:value-of select="$new_row"/>
        <xsl:apply-templates select="/cinema/contacts"/>
        <xsl:apply-templates select="/cinema/staff"/>
    </xsl:template>

    <xsl:template match="cinema/contacts">
        <xsl:text>City: </xsl:text><xsl:value-of select="city"/><xsl:value-of select="$new_row"/>
        <xsl:text>Address: </xsl:text><xsl:value-of select="street"/><xsl:value-of select="$new_row"/>
    </xsl:template>

    <xsl:template match="/cinema/staff">
        <xsl:value-of select="$new_row"/>
        <xsl:text>Тhe following staff work:</xsl:text>
        <xsl:value-of select="$new_row"/>
        <xsl:text>NAME | JOB | EMAIL | SALARY</xsl:text>
        <xsl:value-of select="street"/><xsl:value-of select="$new_row"/>
        <xsl:for-each select = "employee">
            <xsl:value-of select="employeeName"/><xsl:value-of select="$separator"/>
            <xsl:value-of select="@job"/><xsl:value-of select="$separator"/>
            <xsl:value-of select="employeeEmail"/><xsl:value-of select="$separator"/>
            <xsl:value-of select="salary"/><xsl:value-of select="$new_row"/>
        </xsl:for-each>
    </xsl:template>

</xsl:transform>