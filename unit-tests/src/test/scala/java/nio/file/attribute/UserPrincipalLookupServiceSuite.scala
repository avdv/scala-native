package java.nio.file.attribute

import java.nio.file.FileSystems

object UserPrincipalLookupServiceSuite extends tests.Suite {
  val lookupService = FileSystems.getDefault.getUserPrincipalLookupService

  test("lookupPrincipalByName succeeds for `root` user") {
    assert(
      lookupService.lookupPrincipalByName("root").getName == "root")
  }

  test("lookupPrincipalByName throws exception for `gobbledygook` user") {
    assertThrows[UserPrincipalNotFoundException](
      lookupService.lookupPrincipalByName("gobbledygook"))
  }

  test("lookupPrincipalByGroupName succeeds for `root` group") {
    assert(
      lookupService.lookupPrincipalByGroupName("root").getName == "root")
  }

  test("lookupPrincipalByGroupName throws exception for `gobbledygook` group") {
    assertThrows[UserPrincipalNotFoundException](
      lookupService.lookupPrincipalByGroupName("gobbledygook"))
  }
}
